public class RoomMaker {
    private Room generalRoom;
    private Room luxuryRoom;
    private Room deluxRoom;
    
    //constructor
    public RoomMaker(){
        generalRoom = new GeneralRoom();
        luxuryRoom = new LuxuryRoom();
        deluxRoom = new DeluxRoom();
    }

    public void allotGeneralRoom(){
        generalRoom.allot();
    }

    public void allotLuxuryRoom(){
        luxuryRoom.allot();
    }

    public void allotDeluxRoom(){
        deluxRoom.allot();
    }
}