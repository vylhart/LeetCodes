class FizzBuzz {
    private int n;
    private static int i=1;
    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        synchronized(this){
            while(i<=n){
                if((i%3==0 && i%5!=0 && i<=n)){
                    printFizz.run();
                    i++;
                    this.notifyAll();
                }
                else{
                    this.wait();
                }
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        synchronized(this){
            while(i<=n){
                if((i%3!=0 && i%5==0 && i<=n)){
                    printBuzz.run();
                    i++;
                    this.notifyAll();
                }
                else{
                    this.wait();
                }
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        synchronized(this){
            while(i<=n){
                if((i%3==0 && i%5==0 && i<=n)){
                    printFizzBuzz.run();
                    i++;
                    this.notifyAll();
                }
                else{
                    this.wait();
                }
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            while(i<=n){
                if((i%3!=0 && i%5!=0 && i<=n)){
                    printNumber.accept(i);
                    i++;
                    this.notifyAll();
                }
                else{
                    this.wait();
                }
            }
        }
        i=1;
    }
}