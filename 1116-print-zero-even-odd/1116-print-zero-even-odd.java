class ZeroEvenOdd {
    private int n;
    private  int turn0 = 1;
    private  int turn1 = 1;
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for(int i=0; i<n; i++){
            synchronized(this){
                while(turn0==0){
                    this.wait();
                }
                turn0=0;
                printNumber.accept(0);
                this.notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for(int i=2; i<=n; i+=2){
            synchronized(this){
                while(turn1==1 || turn0==1){
                    this.wait();
                }
                turn0=1;
                turn1=1;
                printNumber.accept(i);
                this.notifyAll(); 
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for(int i=1; i<=n; i+=2){
            synchronized(this){
                while(turn1==0 || turn0==1){
                    this.wait();
                }
                turn0=1;
                turn1=0;
                printNumber.accept(i);
                this.notifyAll(); 
            }
        }
    }
}