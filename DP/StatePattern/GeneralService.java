public class GeneralService implements Service{

    @Override
    public void provideService(Room r) {
        System.out.println("General Service Applied to Room: "+r.name);
        r.setService(this);
    }
}
