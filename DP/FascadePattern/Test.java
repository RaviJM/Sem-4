public class Test {
    public static void main(String args[]){

        //one RoomMaker object is enough to call all methods(provide services)
        RoomMaker rm = new RoomMaker();

        rm.allotGeneralRoom();
        rm.allotLuxuryRoom();
        rm.allotDeluxRoom();
    }
}