public class Test {
    public static void main(String args[]){

        Room r = new Room("Room-1");

        PremiumService s1 = new PremiumService();
        s1.provideService(r);

        GeneralService s2 = new GeneralService();
        s2.provideService(r);
    }
}
