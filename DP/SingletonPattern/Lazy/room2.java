/*In Lazy Singleton design pattern,
the object is only instantiated, not created
object is created later during the getRoom function call
this is helpful as it does not occupy more space in the memory
*/

public class room2{
    public static room2 r;      //object is only instantiated here, it is later created inside getRoom() function

    private room2(){     //creating constructor as private so that only one instance can be created
        System.out.println("Room only instatantiated");
    }

    public static room2 getRoom(){
        if (r == null){
            r = new room2();        //object is created here. It is lazy object
            System.out.println("Room created");
        }
        return r;
    }
}