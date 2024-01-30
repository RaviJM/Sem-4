package AbstractFactoryPattern;

public class DoubleRoom implements RoomType{
    @Override
    public void allotRoom(){
        System.out.println("Double Room alloted");
    }
}
