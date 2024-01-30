//This is the Controller class.
//It will have:
//      Model class object
// &    View class object
//as its attributes.

//The main class can only call functions of the controller class
//i.e. The user can only access the controller class methods,
// which will eventually call methods of view or model class depending upon use case.
//In short, methods of other class cannot be called directly.

public class RoomOwnerController {
    private RoomOwner ROModel;
    private RoomOwnerView ROView;

    public RoomOwnerController(RoomOwner ROModel, RoomOwnerView ROView){
        this.ROModel = ROModel;
        this.ROView = ROView;
    }

    public void setRoomOwnerName(String name){
        ROModel.setName(name);
    }

    public String getRoomOwnerName(){
        return ROModel.getName();
    }

    public void displayDetailsOfRoomOwner(){
        ROView.displayDetails(ROModel.getName());
    }
}
