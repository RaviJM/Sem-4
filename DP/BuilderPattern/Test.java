package BuilderPattern;
public class Test {
    public static void main(String args[]){
        room r1 = new RoomBuilder().setAirConditioning("Yes").setCapacity(4).getRoom();
        System.out.println(r1);

        room r2 = new RoomBuilder().setCapacity(2).setLightning("Warm").setBeddingType("Queen Size").setFlooring("Wooden").getRoom();
        System.out.println(r2);
    }
}