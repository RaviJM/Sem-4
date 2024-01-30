public class GeneralRoom extends RoomDecorator{

    public GeneralRoom(Room r) {
        super(r);
    }

    @Override
    public void allot(){
        //first, the super class method is called, so that features of super class get added.
        super.allot();

        System.out.println("Adding General Room Features.");
    }
}