public class Room {
    private Service service;
    String name;

    //Constructor
    public Room(String name){
        service = null;
        this.name = name;
    }

    public void setService(Service service){
        this.service = service;
    }

    public Service getService(){
        return service;
    }
}
