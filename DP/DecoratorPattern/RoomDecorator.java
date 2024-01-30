public class RoomDecorator implements Room{

    protected Room room;

    public RoomDecorator(Room r){
        this.room = r;
    }

    @Override
    public void allot() {
        this.room.allot();
    }
}