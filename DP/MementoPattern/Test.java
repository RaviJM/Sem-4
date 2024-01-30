public class Test {
    public static void main(String args[]){
        Originator originator = new Originator();
        Caretaker caretaker = new Caretaker();

        originator.setOwner("Ravi");
        caretaker.add(originator.saveOwnerToMemento());

        originator.setOwner("Hrishikesh");
        caretaker.add(originator.saveOwnerToMemento());

        originator.setOwner("Kalp");
        
        System.out.println("Current Owner: "+originator.getOwner());

        originator.getOwnerFromMemento(caretaker.get(0));
        System.out.println("First Owner: "+originator.getOwner());

        originator.getOwnerFromMemento(caretaker.get(1));
        System.out.println("Second Owner: "+originator.getOwner());

    }
}

