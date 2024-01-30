public class Test {
    public static void main(String args[]){

        //creating a new General Room
        Room gr = new GeneralRoom(new BasicRoom());
        gr.allot();
        System.out.println();

        //creating a new Luxury Room
        Room lr = new LuxuryRoom(new BasicRoom());
        lr.allot();
        System.out.println();

        //creating a new General Luxury Room
        Room glr = new GeneralRoom(new LuxuryRoom(new BasicRoom()));
        glr.allot();
        System.out.println();
    }
}