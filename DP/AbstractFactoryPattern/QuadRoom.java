package AbstractFactoryPattern;

public class QuadRoom implements RoomType{
    @Override
    public void allotRoom(){
        System.out.println("Quad Room alloted");
    }
}