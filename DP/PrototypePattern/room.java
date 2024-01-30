package PrototypePattern;
public class room {
    int roomNo;
    String cName;

    public String getCname(){
        return cName;
    }
    public int getRoomNo(){
        return roomNo;
    }
    public void setCname(String cName){
        this.cName = cName;
    }
    public void setRoomNo(int roomNo){
        this.roomNo = roomNo;
    }

    @Override
    public String toString(){
        return "Room [roomNo:" + roomNo + " customerName" + cName + "]";
    }
}