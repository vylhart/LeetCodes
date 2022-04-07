class H2O {
    CyclicBarrier barrier = new CyclicBarrier(3);
    Semaphore s1 = new Semaphore(1);
    Semaphore s2 = new Semaphore(2);
    
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        s2.acquire();
        try{
            barrier.await();
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
        }
        catch(BrokenBarrierException e){
            
        }
		releaseOxygen.run();
        
        s1.release();
    }
}