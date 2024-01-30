public class Test {
    public static void main(String args[]){

        //defining composite components
        composite room = new composite("Room");
        composite bed = new composite("Bed");
        composite shoeRack = new composite("Shoe-Rack");

        //defining leaf components
        leaf mattress = new leaf(7000, "Mattress");
        leaf bedsheet = new leaf(1000, "Bedsheet");
        leaf pillow = new leaf(400, "Pillow");
        leaf light = new leaf(300, "Light");
        leaf fan = new leaf(1200, "Fan");
        leaf shoes = new leaf(1400, "Shoes");
        leaf sandals = new leaf(500, "Sandals");



        //adding (sub) components to other (parent) components

        shoeRack.addComponent(shoes);
        shoeRack.addComponent(sandals);

        bed.addComponent(mattress);
        bed.addComponent(bedsheet);
        bed.addComponent(pillow);

        room.addComponent(bed);
        room.addComponent(light);
        room.addComponent(fan);
        room.addComponent(shoeRack);


        
        //calling method for ANY component
        
        System.out.println("CALLING showPrice() METHOD FOR 'bed' OBJECT:");
        bed.showPrice();

        System.out.println("\n\n\n");
        System.out.println("CALLING showPrice() METHOD FOR 'room' OBJECT:");
        room.showPrice();

    }
}