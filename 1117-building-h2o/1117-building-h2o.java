class H2O {
    static CyclicBarrier barrier = new CyclicBarrier(3);
    static CyclicBarrier barrier2 = new CyclicBarrier(2);
    static CountDownLatch latchH = new CountDownLatch(2);
    static CountDownLatch latchO = new CountDownLatch(1);
    static Semaphore s1 = new Semaphore(1);
    static Semaphore s2 = new Semaphore(2);
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        s2.acquire();
        try{
            barrier.await();
            //barrier.notify();
        }
        catch(BrokenBarrierException e){
            
        }
        
        releaseHydrogen.run();
        s2.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        
        s1.acquire();
        try{
            barrier.await();
            //barrier.notify();
        }
        catch(BrokenBarrierException e){
            
        }
        //barrier.notifyAll();
		releaseOxygen.run();
        
        s1.release();
    }
}