package AbstractFactoryPattern;

public class WoodenFlooring implements FlooringType{
    @Override
    public void applyFlooring(){
        System.out.println("Wooden Flooring applied");
    }
}