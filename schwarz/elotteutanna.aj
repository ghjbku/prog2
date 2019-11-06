public aspect elotteutanna {

    public pointcut fgvHívás(): call(public void hello.hi());

    before():fgvHívás(){
        System.out.println("elotteutanna>alma");
    }
    after():fgvHívás(){
        System.out.println("elotteutanna>körte");
    }
}