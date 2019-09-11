public class polargenerator
{

 boolean nincstar=true;
 double tarolt;

 public polargenerator()
	{
	 nincstar=true;
	}


 public double kovetkezo()
	{
	if(nincstar)
		{
		double a1,a2,b1,b2,c;
		
			do{
		  a1=Math.random();
		  a2=Math.random();
		  b1=2*a1-1;
		  b2=2*a2-1;
		  c=b1 * b1 + b2 * b2;
		          }while(c>1);
		double r=Math.sqrt((-2*Math.log(c))/c);
		tarolt=r*b2;
		nincstar=!nincstar;
		return r*b1;
		}
	else
		{
		nincstar=!nincstar;
		return tarolt;		
		}
	
	}

	public static void main(String[] args)
	{polargenerator g = new polargenerator();
	for(int i=0; i<10;++i)
		{
		System.out.println(g.kovetkezo());
		}
	}
}
