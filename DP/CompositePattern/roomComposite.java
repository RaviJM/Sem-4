import java.util.*;

interface component{
    void showPrice();
}

class leaf implements component{
    int price;
    String name;

    //constructor
    public leaf(int price, String name){
        super();
        this.price = price;
        this.name = name;
    }

    @Override
    public void showPrice(){
        System.out.println(name + " " + price);
    }
}

class composite implements component{
    String name;
    List <component> components = new ArrayList<>();

    //constructor
    public composite(String name){
        super();
        this.name = name;
    }

    public void addComponent(component c){
        components.add(c);
    }

    @Override
    public void showPrice(){
        System.out.println(name);
        for (component c : components){
            c.showPrice();
        }
    }
}