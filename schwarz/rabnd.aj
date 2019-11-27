public class A
{
    public int foo()
    {
        return 0;
    }
 
    public void bar()
    {
        x();
    }
 
    public void x()
    {
    }
};
 
aspect LogExecutionTime
{
    pointcut allMethods() : execution(public * A.*(..));
    void around() : allMethods()
    {
        long startTime = System.currentMilliSeconds();
        proceed();
        long time = System.currentMilliSeconds() - startTime;
        System.out.println("Time taken by method " + thisJoinPoint.getSignature() + " " + time "ms"); 
    }
}