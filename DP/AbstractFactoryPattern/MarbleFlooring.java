package AbstractFactoryPattern;

public class MarbleFlooring implements FlooringType{
    @Override
    public void applyFlooring(){
        System.out.println("Marble Flooring applied");
    }
}