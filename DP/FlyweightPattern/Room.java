/*
 * Flyweight DP is used when we need to create lots of objects of same class
 * which will lead to lot of memory usage.
 * So, instead we can create the object only once and then share the attributes
 * of that object instead of creating separate objects eveytime.
 */


/*
 * Shared properties(attributes) are called Intrinsic state
 * Properties(attributes) NOT shared are called Extrinsic state.
 */


/*
 * All Rooms share prop. like number of lights, fans, chairs, tables (Intrinsic states)
 * but they do not share some prop. like availability of AC, flooring type
 */
public interface Room{

    public void setFlooring(String Flooring);
    public void setACavailability(String ac);

    public void showProperties();

}
