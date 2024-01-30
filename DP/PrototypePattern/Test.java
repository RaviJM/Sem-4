package PrototypePattern;

public class Test {
    public static void main(String args[]) throws CloneNotSupportedException{

        hotel h1 = new hotel();
        h1.setHotelName("H1");
        h1.loadData();

        hotel h2 = h1.clone();
        h1.getRooms().remove(3);
        h2.setHotelName("H2");

        System.out.println(h1);
        System.out.println(h2);

    }
}