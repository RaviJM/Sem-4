// This class holds list of values for all versions of the mementos
// In this case, it holds the list of names of all owners of the room
import java.util.ArrayList;
import java.util.List;

public class Caretaker {
    private List<Memento> ownerList = new ArrayList<Memento>();

    public void add(Memento owner){
        ownerList.add(owner);
    }

    public Memento get(int index){
        return ownerList.get(index);
    }
}

