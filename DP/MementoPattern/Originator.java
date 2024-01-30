// This class gets and sets values from current memento(object)
// also it creates new memento objects
public class Originator {
    private String owner;

    public void setOwner(String owner){
        this.owner = owner;
    }

    public String getOwner(){
        return owner;
    }

    public Memento saveOwnerToMemento(){
        return new Memento(owner);
    }

    public void getOwnerFromMemento(Memento memento){
        owner = memento.getOwner();
    }
}

    