public class LuxuryRoom extends RoomDecorator{

    public LuxuryRoom(Room r) {
        super(r);
    }

    @Override
    public void allot(){
        //first, the super class method is called, so that features of super class get added.
        super.allot();

        System.out.println("Adding Luxury Room Features.");
    }
}