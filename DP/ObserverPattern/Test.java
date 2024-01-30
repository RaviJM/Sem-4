public class Test {
    public static void main(String args[]){
        
        //Creating Hotel.
        Hotel h1 = new Hotel("Krupa");

        //Creating room owners.
        RoomOwner r1 = new RoomOwner("Ravi");
        RoomOwner r2 = new RoomOwner("Dhyey");
        RoomOwner r3 = new RoomOwner("Hrishikesh");
        RoomOwner r4 = new RoomOwner("Kalp");
        
        //Adding room owners to the list of hotel.
        h1.addOwnerToList(r1);
        h1.addOwnerToList(r2);
        h1.addOwnerToList(r3);
        h1.addOwnerToList(r4);
        
        //Hotel making its food for mess,
        //(which will internally call function to notify all room owners).
        h1.makeFood("Manchurian");
    }
}
