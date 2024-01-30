/*In Eager Singleton design pattern,
although only one object is created, it is created the moment the constructor is called,
so it occupies a lot of memory in the system
*/

public class room1{
    public static final room1 r = new room1();  //creating static object

    private room1(){     //creating constructor as private so that only one instance can be created

    }

    public static room1 getRoom(){
        return r;
    }

    public void printAlloted(){
        System.out.println("Room created");
    }
}
