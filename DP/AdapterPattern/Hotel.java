//Hotel class that only works with objects of class GeneralRoom
public class Hotel{

    public GeneralRoom gr;

    public GeneralRoom getGeneralRoom(){
        return gr;
    }

    public void setGeneralRoom(GeneralRoom gr){
        this.gr = gr;
    }
    public void allotRoom(String r){
        gr.allot(r);
    }
}
