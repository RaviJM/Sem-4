/*
 * In synchronized method of singleton design pattern,
 * the main objective is that only one object is created,
 * even if we use multithreading
 */

public class room3{
    static int counter=0;

    public static room3 r;

    private room3(){     //creating constructor as private so that only one instance can be created
        System.out.print("Room instantiated");
        counter++;
        System.out.println("     Room object instantiated: "+ counter + " times.");
    }

    public static room3 getRoom(){
        if (r == null){
            synchronized (room3.class){     //put synchronized here
                if (r == null)      //double checking for null
                r = new room3();        //object created is lazy
                System.out.println("Room created");
            }
        }
        return r;
    }
}
