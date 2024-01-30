package AbstractFactoryPattern;

public class Test {
    public static void main(String args[]){
        //get RoomFactory
        AbstractFactory rf = FactoryProducer.getFactory("Room");

        //get type of room
        RoomType a1 = rf.getRoomType("Single");

        //call method allotRoom for this room object
        a1.allotRoom();

        


        //get FlooringFactory
        AbstractFactory ff = FactoryProducer.getFactory("Flooring");

        //get flooring type
        FlooringType a2 = ff.getFlooringType("Wooden");

        //call method applyFlooring for this flooring object
        a2.applyFlooring();
    }
}