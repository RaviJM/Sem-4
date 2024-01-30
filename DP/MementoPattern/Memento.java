// In memento class, we will basically store the name of current owner of the room
// (room is memento(object))
public class Memento{
    private String owner;

    public Memento(String owner){
        this.owner = owner;
    }
    public String getOwner(){
        return owner;
    }
}

