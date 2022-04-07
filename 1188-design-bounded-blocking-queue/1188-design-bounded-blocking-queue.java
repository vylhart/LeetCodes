class BoundedBlockingQueue {
    Semaphore full, empty;
    Queue<Integer> q;
    public BoundedBlockingQueue(int capacity) {
        full = new Semaphore(capacity);
        empty = new Semaphore(0);
        q = new LinkedList<>();
    }
    
    public void enqueue(int element) throws InterruptedException {
        full.acquire();
        synchronized(this){
            q.add(element);
        }
        empty.release(1);

    }
    
    public int dequeue() throws InterruptedException {
        empty.acquire();
        int x = -1;
        synchronized(this){
            x = q.remove();
            full.release();    
        }
        return x;
    }
    
    public int size() {
        return q.size();
    }
}