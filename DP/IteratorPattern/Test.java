public class Test {
    public static void main(String args[]){
        RoomOwnersRepository ror= new RoomOwnersRepository();

        for (Iterator iter=ror.getIterator(); iter.hasNext();){
            String n = (String)iter.next();
            System.out.println("Name: "+n);
        }
    }
}
