package AbstractFactoryPattern;

public class FactoryProducer{


    //this is factory of factories, so we use this factory (super) to select other factories, to further make objects

    //AbstractFactory method returns object of input type AbstractFactory
    public static AbstractFactory getFactory (String choice){
        if (choice.equalsIgnoreCase("Room")){
            return new RoomFactory();
        }
        else if (choice.equalsIgnoreCase("Flooring")){
            return new FloorFactory();
        }
        return null;
    }
}