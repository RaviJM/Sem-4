package AbstractFactoryPattern;

public class RoomFactory extends AbstractFactory{

    //getRoomType method returns object of input type RoomType
    @Override
    public RoomType getRoomType(String roomtype){
        if (roomtype == null){
            return null;
        }
        if (roomtype.equalsIgnoreCase("Single")){
            return new SingleRoom();
        }
        else if (roomtype.equalsIgnoreCase("Double")){
            return new DoubleRoom();
        }
        else if (roomtype.equalsIgnoreCase("Quad")){
            return new QuadRoom();
        }
        return null;
    }


    @Override
    public FlooringType getFlooringType(String flooring){
        return null;
    }
}