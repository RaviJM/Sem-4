public class Test3 {
    public static void main(String args[]){

        Thread t1 = new Thread (new Runnable() {
            public void run(){
                room3 r = room3.getRoom();
            }
        });

        Thread t2 = new Thread (new Runnable() {
            public void run(){
                room3 r = room3.getRoom();
                //although it is another thread trying to create a new object, no new object will be created.
                //the object created by thread-1 will only be used to call the method again
            }
        });

        t1.start();
        t2.start();
    }
}
