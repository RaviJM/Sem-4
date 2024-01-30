public class Test{
    public static void main(String args[]){

        //make model (i.e. a RoomOwner object) using below function.
        RoomOwner model = createModelOfRoomOwner();
        //make view.
        RoomOwnerView view = new RoomOwnerView();
        //make controller.
        RoomOwnerController controller= new RoomOwnerController(model, view);

        controller.displayDetailsOfRoomOwner();
        controller.setRoomOwnerName("Meet");
        controller.displayDetailsOfRoomOwner();
    }

    private static RoomOwner createModelOfRoomOwner(){
        RoomOwner ro = new RoomOwner();
        ro.setName("Ravi");
        return ro;
    }
}
