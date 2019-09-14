import java.io.*;
public class Hungarian
{
	public static void main(String[] args)
	{
	try
	   {
		Writer w=new OutputStreamWriter(System.out,"8859_2");
		w.write("tekn\u0150s");
		System.out.println();
		w.write("turtle");
		w.close();
	   }
	catch(Exception e)
	   {
		System.out.println("can't use utf-8");
	   }
	}

}
