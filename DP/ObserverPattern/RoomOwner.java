// This class is for Room Owner.
// Each object created will account for one room owner.

public class RoomOwner {
    String name;
    
    public RoomOwner(String name){
        this.name = name;
    }
    public void updateAboutFood(){
        System.out.println("Hey "+name+" Food is now available is the mess.");
    }
}
