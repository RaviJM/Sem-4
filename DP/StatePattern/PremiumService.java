public class PremiumService implements Service{

    @Override
    public void provideService(Room r) {
        System.out.println("Premium Service Applied to Room: "+r.name);
        r.setService(this);
    }
}
