//Adapter class to make the LuxuryRoom class compatible with the Hotel class
public class AdapterRoom extends GeneralRoom{

    LuxuryRoom lr = new LuxuryRoom();

    @Override
    public void allot(String s) {
        lr.allot(s);
    }
}
