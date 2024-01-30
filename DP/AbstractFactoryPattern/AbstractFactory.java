package AbstractFactoryPattern;

public abstract class AbstractFactory {
    abstract RoomType getRoomType(String room);
    abstract FlooringType getFlooringType(String flooring);
}