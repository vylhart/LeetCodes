class DiningPhilosophers {
    
    public DiningPhilosophers() {
        
    }
    int i=0;
    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        synchronized(this){
            while(philosopher!=i){
                this.wait();
            }
            if(philosopher==i){
                pickLeftFork.run();
                pickRightFork.run();
                eat.run();
                putRightFork.run();
                putLeftFork.run();
                i=(i+2)%5;
                this.notifyAll();
            }
        }
    }
}