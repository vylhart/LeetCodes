class FooBar {
    private int n;
    private static Semaphore semaphore = new Semaphore(1);
    private static CountDownLatch latch = new CountDownLatch(1);
    private static Lock lock = new ReentrantLock();
    private static CyclicBarrier barrier = new CyclicBarrier(2);
    private static int turn = 1;
    
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            synchronized(this){
                while(turn==0)  this.wait();
                printFoo.run();
                turn = 0;
                latch.countDown();
                this.notify();
            }
            
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        latch.await();
        for (int i = 0; i < n; i++) {
            synchronized(this){
                while(turn==1)  this.wait();
                printBar.run();
                turn = 1;
                this.notify();
            }
            //semaphore.release();
        }
        //latch = new CountDownLatch(1);
    }
}