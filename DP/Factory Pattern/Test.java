public class Test{
    public static void main(String args[]) throws NullPointerException{
        
        RoomFactory rf = new RoomFactory();

        try{
            
            room r1 = rf.getRoom("SINGLE");
            r1.allot();
    
            room r2 = rf.getRoom("QUADRUPLE");
            r2.allot();
    
            room r3 = rf.getRoom("DOUBLE");
            r3.allot();
            
            room r4 = rf.getRoom("Ravi");
            r4.allot();
        }

        catch (NullPointerException ex){
            System.out.println("Room not available!");
        }
    }
}