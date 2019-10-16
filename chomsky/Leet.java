import java.util.Scanner;
import java.util.Vector;


public class Leet {

    public static Vector<String> translate(String word, Vector<String> wordvect)
    {
        
        word=word.toUpperCase();
        for(int i=0;i<word.length();i++)
        {
            switch (word.charAt(i)) {
                case 'A' : wordvect.add("4");
                     break;
                case 'B' : wordvect.add("|3");
                     break;
                case 'C' : wordvect.add("(");
                     break;
                case 'D' : wordvect.add("|)");
                     break;
                case 'E' : wordvect.add("3");
                     break;
                case 'F' : wordvect.add("|=");
                     break;
                case 'G' : wordvect.add("6");
                     break;
                case 'H' : wordvect.add("|-|");
                     break;
                case 'I' : wordvect.add("|");
                     break;     
                case 'J' : wordvect.add(".]");
                     break;
                case 'K' : wordvect.add("|<");
                     break;      
                case 'L' : wordvect.add("1");
                     break;      
                case 'M' : wordvect.add("|Y|");
                     break;
                case 'N' : wordvect.add("N");
                     break;
                case 'O' : wordvect.add("0");
                     break;
                 case 'P' : wordvect.add("P");
                     break;
                case 'Q' : wordvect.add("Q");
                     break;
                case 'R' : wordvect.add("|2");
                     break;
                case 'S' : wordvect.add("5");
                     break;
                case 'T' : wordvect.add("7");
                     break;
                case 'U' : wordvect.add("|_|");
                     break;                    
                case 'V' : wordvect.add("V");
                     break;
                case 'W' : wordvect.add("W");
                     break;                    
                case 'X' : wordvect.add("}{");
                     break;                     
                case 'Y' : wordvect.add("'/");
                     break;
                case 'Z' : wordvect.add("2");
                     break;
                case ' ' : wordvect.add(" ");
                     break;      
            }
        
        
        }
        
    return wordvect; 
    }
    
    public static void main(String[] args) {
       Vector<String> wordvect = new Vector<>();
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
       
       wordvect=translate(word,wordvect);
               
       for(int i=0;i<wordvect.size();i++)
         System.out.print(wordvect.get(i));
       
       System.out.print("\n");
       System.out.println("tovább?(y / n)");
       question=scan.nextLine();
       if(question.startsWith("y"))
       {
           wordvect.clear();
           questionbool = true;
       }
       else
           break;
      }
       
    }
    
}
