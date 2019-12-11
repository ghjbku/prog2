import java.util.Scanner;
import java.util.Vector;
import java.util.HashMap;
import java.util.Random;
import java.util.Map.Entry;


public class Leet {
private String sb,word;
private Random rand;


         private HashMap<String, String[]> leet = new HashMap<String, String[]>() {{
		put("a", new String[] { "4", "4", "@", "-" });
		put("b", new String[] { "b", "8", "3", "}" });
		put("c", new String[] { "c", "(", "", "{" });
		put("d", new String[] { "d", ")", "]", "}" });
		put("e", new String[] { "3", "3", "3", "3" });
		put("f", new String[] { "f", "=", "ph", "#" });
		put("g", new String[] { "g", "6", "[", "[+" });
		put("h", new String[] { "h", "4", "-", "[-]" });
		put("i", new String[] { "1", "1", "", "!" });
		put("j", new String[] { "j", "7", "_", "_" });
		put("k", new String[] { "k", "", "1", "{" });
		put("l", new String[] { "l", "1", "", "_" });
		put("m", new String[] { "m", "44", "(V)", "" });
		put("n", new String[] { "n", "", "", "V" });
		put("o", new String[] { "0", "0", "()", "[]" });
		put("p", new String[] { "p", "o", "D", "o" });
		put("q", new String[] { "q", "9", "O_", "(,)" });
		put("r", new String[] { "r", "12", "12", "2" });
		put("s", new String[] { "s", "5", "$", "$" });
		put("t", new String[] { "t", "7", "7", "''" });
		put("u", new String[] { "u", "_", "(_)", "[_]" });
		put("v", new String[] { "v", "", "", "" });
		put("w", new String[] { "w", "VV", "", "()" });
		put("x", new String[] { "x", "%", ")(", ")(" });
		put("y", new String[] { "y", "", "", "" });
		put("z", new String[] { "z", "2", "7_", "_" });

		put("0", new String[] { "D", "0", "D", "0" });
		put("1", new String[] { "I", "I", "L", "L" });
		put("2", new String[] { "Z", "Z", "Z", "e" });
		put("3", new String[] { "E", "E", "E", "E" });
		put("4", new String[] { "h", "h", "A", "A" });
		put("5", new String[] { "S", "S", "S", "S" });
		put("6", new String[] { "b", "b", "G", "G" });
		put("7", new String[] { "T", "T", "j", "j" });
		put("8", new String[] { "X", "X", "X", "X" });
		put("9", new String[] { "g", "g", "j", "j" });
	}};


     public Leet(String word) {
		rand = new Random();
		this.word = word;
	}

    public Leet translate() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            String loc = Character.toString(Character.toLowerCase(c));
            if (leet.containsKey(loc))
            	sb.append(leet.get(loc)[rand.nextInt(leet.get(loc).length)]);
            else
            	sb.append(c);
        }
		this.sb = sb.toString();
		
		return this;
	}

public String getLeet() {
		return this.sb;
	}


    public static void main(String[] args) {
       String wordvect;
       Scanner scan = new Scanner(System.in);
       String word;
       String question;
       boolean questionbool = true;
 
      while(questionbool=true)
      {
       questionbool=false;
       System.out.println("irj be egy szót!");
       word=scan.nextLine();
       System.out.println("szó: "+word);
       wordvect=(new Leet(word).translate().getLeet());
       System.out.println(wordvect);

       System.out.print("\n");
       System.out.println("tovább?(y / n)");
       question=scan.nextLine();
       if(question.startsWith("y"))
       {
           wordvect=null;
           questionbool = true;
       }
       else
           break;
      }
       
    }
    
}
