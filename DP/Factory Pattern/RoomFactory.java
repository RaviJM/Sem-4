public class RoomFactory {
    public room getRoom(String roomType){
        if (roomType == null){
            return null;
        }
        if (roomType.equalsIgnoreCase("single")){
            return new single_room();
        }
        else if (roomType.equalsIgnoreCase("double")){
            return new double_room();
        }
        else if (roomType.equalsIgnoreCase("quadruple")){
            return new quadruple_room();
        }
        else{
            return null;
        }
    }
}