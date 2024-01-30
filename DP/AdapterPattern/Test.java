public class Test {
    public static void main(String args[]){

        Hotel h = new Hotel();

        
        /*  below code works perfectly fine, because object of type GeneralRoom
        is an attribute of the Hotel class.
        */
        GeneralRoom gr = new GeneralRoom();
        h.setGeneralRoom(gr);
        h.allotRoom("Room alloted");



        /*  But below code cannot work because object of type LuxuryRoom
            is not an attribute of Hotel class.
        */

        // LuxuryRoom lr = new LuxuryRoom();
        // h.setGeneralRoom(lr);
        // h.allotRoom("Luxury Room alloted.");



        //  To solve this issue, we create and use the Adapter class
        AdapterRoom r1 = new AdapterRoom();
        h.setGeneralRoom(r1);
        h.allotRoom("Room alloted");
    }
}
