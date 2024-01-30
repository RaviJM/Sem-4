public class Test1 {
    public static void main(String args[]){

        room1 r1 = room1.getRoom();
        r1.printAlloted();

        room1 r2 = room1.getRoom();
        r2.printAlloted();

        // room r3 = new room();        this is not possible as constructor of the class "room" is private
    }
}
