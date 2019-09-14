public class Osztas
{
 static java.io.StreamTokenizer st= new java.io.StreamTokenizer(new java.io.InputStreamReader(System.in));
	public static int readNumber(String kerdes) throws java.io.IOException{
	while(st.ttype != java.io.StreamTokenizer.TT_NUMBER){
		System.out.print(kerdes);
		st.nextToken();
	}
	return (int)st.nval;
	}

 public static void main(String[] args)
 {
	try
	{
	int szam = readNumber("write a number:");
	System.out.println("100 /" + szam + " = " + 100/szam);
	}
	 catch(java.io.IOException e)
		{
		System.err.println("couldn't read the number...");
		} 
	 catch(ArithmeticException e)
		{
		System.err.println("the division couldn't be made...");	
		}
 }
}
