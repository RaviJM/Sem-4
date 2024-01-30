package PrototypePattern;
import java.util.ArrayList;
import java.util.List;

public class hotel implements Cloneable{
    String hotelName;
    List<room> rooms = new ArrayList<>();

    public String getHotelName(){
        return hotelName;
    }
    public void setHotelName(String hotelName){
        this.hotelName = hotelName;
    }
    public List<room> getRooms(){
        return rooms;
    }
    public void setRooms(List<room> rooms){
        this.rooms = rooms;
    }
    public void loadData(){
        for(int i=1; i<=5; i++){
            room b= new room();
            b.setRoomNo(i);
            b.setCname("Room"+i);
            getRooms().add(b);
        }
    }

    @Override
    public String toString(){
        return "Hotel [HotelName="+ hotelName+ ", rooms="+ rooms+ "]";
    }

    public hotel clone() throws CloneNotSupportedException{
        hotel h = new hotel();
        for (room r : this.getRooms()){
            h.getRooms().add(r);
        }
        return h;
    }
}