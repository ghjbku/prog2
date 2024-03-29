import java.math.BigInteger;
import java.nio.charset.Charset;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Random;
import javax.print.DocFlavor.BYTE_ARRAY;
public class RSA {
BigInteger p , q , n , tn , e ,d;

public RSA() {
p = new BigInteger(100,new Random());
q = new BigInteger(100,new Random());
n = p.multiply(q);
tn = (p.subtract(BigInteger.ONE)).multiply((q.subtract(BigInteger.ONE)));
do {
e = new BigInteger(100,new Random());
}while ( !(e.compareTo(BigInteger.ONE) == 1) && !(e.compareTo(tn) == -1) );
//e = new BigInteger("17");
do {
d = ( (BigInteger.ONE).add( (new BigInteger(100,new Random())).multiply(tn) ) ).divide(e);
}while ( (( (d.multiply(e)).subtract(BigInteger.ONE) ).mod(tn)).equals(BigInteger.ZERO) );
//d = e.modInverse(tn);
}

public BigInteger[] encript(String msg) {
byte[] buffer = msg.getBytes();
java.math.BigInteger[] priv = new java.math.BigInteger[buffer.length];
for (int i = 0 ; i < priv.length ; i++) {
priv[i] = new java.math.BigInteger(new byte[] {buffer[i]});
priv[i] = priv[i].modPow(this.e, this.n);
}
return priv;
}
public String atlagDecrypt(String clean ,BigInteger[] msg , Map<Character,Integer> m) {
byte[] buffer = clean.getBytes();
for (int i = 0 ; i < msg.length ; i++) {
msg[i] = msg[i].modPow(this.d, this.n);
buffer[i] = msg[i].byteValue();
}
String wrong_dm = new String(buffer);
System.out.println("\nencripted private msg: " + wrong_dm+"\n");
Map<Character,Integer> currentMap = new HashMap<>();
for (char i : wrong_dm.toCharArray()) {
if(currentMap.containsKey(i)) currentMap.put(i, currentMap.get(i) + 1);
else currentMap.put(i, 1);
}
for (Iterator it = currentMap.entrySet().iterator();it.hasNext();) {
Map.Entry pair = (Map.Entry)it.next();
System.out.println( pair.getKey() + " " + pair.getValue() );
}
for (int i = 0 ; i < wrong_dm.length() ; i++) {
Character c;
if ( ( (c = contains(currentMap.get(wrong_dm.charAt(i)),m )) != null )) {
wrong_dm =wrong_dm.replace(wrong_dm.charAt(i), c);
currentMap.remove(wrong_dm.charAt(i));
}
}
return wrong_dm;
}
public BigInteger getE() {
return this.e;
}
public BigInteger getN() {
return this.n;
}
public static Character contains(Integer numContained , Map<Character,Integer> m) {
for (Iterator it = m.entrySet().iterator() ; it.hasNext();) {
Map.Entry pair = (Map.Entry)it.next();
if ( pair.getValue() == numContained ) {
Character c = (Character)pair.getKey();
m.remove(c);
return c;
}
}
return null;
}
public static Map<Character,Integer> toMap(String privateMsg){
Map<Character,Integer> currentMap = new HashMap<>();
for (char i : privateMsg.toCharArray()) {
if(currentMap.containsKey(i)) currentMap.put(i, currentMap.get(i) + 1);
else currentMap.put(i, 1);
}
return currentMap;
}
public static void main(String[] args) {
RSA obj = new RSA();
String privateMsg = "az ipar számára a professzionális programozó, a tudománynak és az emberiségnek a komplex problémákkal megküzdeni tudó algoritmuselmélész, az egyénnek és a társadalomnak a boldog és tetterős polgár. Reményeink szerint ennek az érzésnek az átadásához ezzel a digitális szakkönyvvel mi is hozzá tudunk járulni, miközben általában foglalkozunk a programozással, annak elméletével és filozófiájával, majd részletesen és gyakorlatiasan az objektumorientált paradigmával, és ezen belül a Java programozással. Ebben a kézikönyvben a Java nyelvvel egy labirintus játék világának felépítése során ismerkedünk meg, ami során ezt az egyszerű, példa labirintus játékot elkészítjük a weboldalon elhelyezhető appletként, mobiltelefonos és teljes képernyős\n PC-s, illetve hálózati: TCP/IP, Java Servlet, Java RMI és CORBA változatban is. De ezeken a labirintus témájú esettanulmányokon túl biológiai, matematikai és informatikai programozási példákkal is megismerkedhet majd a kedves Olvasó.";
BigInteger[] msg = obj.encript(privateMsg);
Map<Character,Integer> m = toMap(privateMsg);
System.out.println("character map of the private message: " + m.toString());
System.out.println("the result of the decryption: " + obj.atlagDecrypt(privateMsg,msg,m));
System.out.println("\nthe thing was: \n" + privateMsg);
}
}