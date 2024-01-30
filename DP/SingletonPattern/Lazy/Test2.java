public class Test2 {
    public static void main(String args[]){

        room2 r1 = room2.getRoom();

        room2 r2 = room2.getRoom();     //although we try to create so many rooms, only one room is created
        room2 r3 = room2.getRoom();     //and we can call methods only for that object
        room2 r4 = room2.getRoom();
        room2 r5 = room2.getRoom();
        room2 r6 = room2.getRoom();
    }
}