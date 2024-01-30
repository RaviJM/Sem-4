package AbstractFactoryPattern;

public class SingleRoom implements RoomType{
    @Override
    public void allotRoom(){
        System.out.println("Single Room alloted");
    }
}