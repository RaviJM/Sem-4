//This class is for Hotel.
//Hotel can add/remove room owners to their list.
//Hotel can make food.
//Hotel can notify all room owners about food availibility in mess.

import java.util.ArrayList;
import java.util.List;

public class Hotel{

    private String food;
    public String name;
    List <RoomOwner> lst = new ArrayList<>();

    public Hotel(String name){
        this.name = name;
    }

    public void addOwnerToList(RoomOwner ro){
        lst.add(ro);
    }

    public void removeOwnerFromList(RoomOwner ro){
        lst.remove(ro);
    }

    public void notifyAllRoomOwners(){
        for (RoomOwner ro: lst){
            ro.updateAboutFood();
        }
    }

    public void makeFood(String food){
        this.food = food;
        notifyAllRoomOwners();
    }
}
