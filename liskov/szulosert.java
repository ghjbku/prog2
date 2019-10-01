class szulo
{
protected int m_age;
protected String m_name;
    public void setAge(int age) {
    m_age = age;
    }
    public void setName(String name) {
    m_name = name;
    }
    public int getAge(){
    return m_age;
    }
}
class gyerek extends szulo
{
    public String getName() {
    return m_name;
    }
}
class szuloGyerek
{
    public static void main (String args[])
    {
    szulo s = new gyerek();
    s.setName("Apuci");
    s.setAge(60);
    gyerek gy = new gyerek();
    s.setName("Laci");
    s.setAge(15);

    System.out.println(gy.getName() + " " + s.getName());
    }
}