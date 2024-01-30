package Enum;

public class Test {
    public static void main(String args[]){
        room r1 = room.INSTANCE;
        System.out.print("Value of i for object r1 is: ");
        System.out.println(r1.getI());

        r1.setI(2);
        System.out.print("Value of i for object r1 is: ");
        System.out.println(r1.getI());

        room r2 = room.INSTANCE;
        r2.setI(5);     //we set value of attribute 'i' of object r2

        System.out.print("Value of i for object r1 is: ");
        System.out.println(r1.getI());  //although we call getI() function for 1st object,
                    //whose attribute's value we set above as 2, we get the value of i as 5
    }
}

enum room{
    INSTANCE;
    int i;

    public int getI(){
        return i;
    }

    public void setI(int i){
        this.i = i;
    }
}