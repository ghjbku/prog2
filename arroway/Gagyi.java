public class Gagyi
{
public static void main(String[] args)
    {
        Integer x = Integer.valueof(args[0]);
        Integer t = Integer.valueof(args[1]);
    System.out.println("x: " +x);
    System.out.println("t: " +t);
    System.out.print("(x <=t && x >= t && (int)t != (int)x)");
    while (x <= t && x>= t && (int)t != (int)x)
    System.out.println("kilép");
    System.out.print("(x <=t && x >=t && t!= x)");
    while(x <=t && x >=t && t!= x)
    System.out.println("kilép");
    }

}