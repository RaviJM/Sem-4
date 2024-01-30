public class GeneralRoom implements Room{
    //common attributes (Intrinsic state)
    private final int numberOfLights;
    private final int numberOfFans;
    private final int numberOfChairs;
    private final int numberOfTables;

    //NON-common attributes (Extrinsic state)
    private String flooring;
    private String ac;
    

    //put THOSE things (initilize those things) in constructor,
    //which will be COMMON attributes for all objects (Instrinsic state).
    public GeneralRoom(){
        this.numberOfLights = 4;
        this.numberOfFans = 2;
        this.numberOfChairs = 2;
        this.numberOfTables = 3;
    }
    
    //below methods are for initializing Extrinsic state (for attributes that are NOT common).
    @Override
    public void setFlooring(String flooring) {
        this.flooring = flooring;
    }
    
    @Override
    public void setACavailability(String ac) {
        this.ac = ac;
    }

    @Override
    public void showProperties() {
        System.out.println("Properties of room are:");
        System.out.println("Number of Lights: "+numberOfLights);
        System.out.println("Number of Fans: "+numberOfFans);
        System.out.println("Number of Chairs: "+numberOfChairs);
        System.out.println("Number of Tables: "+numberOfTables);
        System.out.println("**Flooring Type: "+flooring);
        System.out.println("**AC Available: "+ac);
        System.out.println("----------------------------------------");
    }
}
