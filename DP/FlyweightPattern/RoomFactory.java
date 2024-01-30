import java.util.*;
public class RoomFactory {
    public static HashMap<String,Room> m = new HashMap<String,Room>();

    public static Room getRoom (String st){
        Room r = null;

        //if object of that type exists in the map..
        if (m.get(st) != null){
            r = m.get(st);
        }

        //if object of that type does NOT exist in the map..
        //then CREATE the object and
        //then add it to the map
        else{
            if (st.equalsIgnoreCase("GeneralRoom")){
                System.out.println("ROOM OBJECT CREATED");
                //new object created
                r = new GeneralRoom();
            }
            else{
                System.out.println("NO SUCH ROOM AVAILABLE");
            }
            //add the object created to the map
            m.put(st,r);
        }
        return r;
    }
}
