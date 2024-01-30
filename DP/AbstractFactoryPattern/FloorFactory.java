package AbstractFactoryPattern;

public class FloorFactory extends AbstractFactory{

    //getFlooringType method returns object of input type FlooringType
    @Override
    FlooringType getFlooringType(String flooring){
        if (flooring == null){
            return null;
        }
        if (flooring.equalsIgnoreCase("Marble")){
            return new MarbleFlooring();
        }
        else if (flooring.equalsIgnoreCase("Wooden")){
            return new WoodenFlooring();
        }
        return null;
    }

    @Override
    RoomType getRoomType(String room){
        return null;
    }
}