import java.awt.*;
import javax.swing.JFrame;

public class bucky extends JFrame
{
	public static void main (String[] args)
	{
	DisplayMode dm = new DisplayMode(800,600,16,DisplayMode.REFRESH_RATE_UNKNOWN);
	bucky b = new bucky();
	b.run(dm);
	}

	public void run(DisplayMode dm)

		{
		setBackground(Color.BLACK);
		setForeground(Color.WHITE);
		setFont(new Font("Arial",Font.PLAIN, 24));
	
		Screen s = new Screen();
		try{
		s.SetFullScreen(dm, this);
			try{
			Thread.sleep(2700);
			
		}catch(Exception ex){}
		}finally{
			s.RestoreScreen();
		}
	}
	 
	public void paint(Graphics g)
	{
	
	g.drawString("This...A programozásra gondolva olykor valami misztikus érzés járja ",200,200);
g.drawString("át az embert, ami további hajtóerőt és lelkesedést kölcsönöz. A sikeres oktatás ",200,300);
g.drawString("elsődleges célja ennek átadása, ebből fejlődhet majd ki minden más, ami csak kell:",200,400); 
g.drawString(" A könyvet elsősorban\n tanári kézikönyvként ajánljuk középiskolai informatikatanároknak, de kiegészítő\n irodalomként hasznos olvasmánynak tartjuk informatikus tanárjelöltek, diákok és általában a programozni tanulni vágyók számára \negyaránt. ",200,450);
g.drawString("az ipar számára a professzionális programozó, a tudománynak és az emberiségnek a komplex problémákkal megküzdeni tudó algoritmuselmélész, az\n egyénnek és a társadalomnak a boldog és tetterős polgár. Reményeink szerint ennek az érzésnek az átadásához ezzel a digitális szakkönyvvel \nmi is hozzá tudunk járulni, miközben általában foglalkozunk \na programozással, annak elméletével és filozófiájával, majd részletesen és gyakorlatiasan az objektumorientált paradigmával, és ezen belül\n a Java programozással. Ebben a kézikönyvben\n a Java nyelvvel egy labirintus játék világának felépítése során ismerkedünk meg, a\nmi során ezt az egyszerű, példa labirintus játékot elkészítjük a weboldalon elhelyezhető appletként, mobiltelefonos és teljes képernyős\n PC-s, illetve hálózati: TCP/IP, Java Servlet\n, Java RMI és CORBA változatban is. De ezeken a labirintus témájú esettanulmányokon túl biológiai, matematikai és informatikai programozási példákkal is megismerkedhet majd \na kedves Olvasó.",200, 500);
	}
}
