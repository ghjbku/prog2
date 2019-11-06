public aspect helyette{
    public pointcut fgvhivas(): call(public void hello.hi());

    void around(): fgvhivas(){
        System.out.println("helyette");
    }
}