public class Test {
    public static void main(String args[]){
        Room r1 = RoomFactory.getRoom("GeneralRoom");
        r1.setFlooring("Wooden");
        r1.setACavailability("Yes");
        r1.showProperties();

        Room r2 = RoomFactory.getRoom("GeneralRoom");
        r2.setFlooring("Marble");
        r2.setACavailability("NO");
        r2.showProperties();
    }
}
