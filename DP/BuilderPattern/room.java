package BuilderPattern;
public class room {
    int capacity;
    String airConditioning;
    String beddingType;
    String breakfast;
    String kitchenFacility;
    String flooring;
    String lightning;

    room(int capacity, String airConditioning, String beddingType, String breakfast, String kitchenFacility, String flooring, String lightning){
        this.capacity = capacity;
        this.airConditioning = airConditioning;
        this.beddingType = beddingType;
        this.breakfast = breakfast;
        this.kitchenFacility = kitchenFacility;
        this.flooring = flooring;
        this.lightning = lightning;
    }

    @Override
    public String toString(){
        return "Room[Capacity: "+capacity+", Air-Conditioning: "+airConditioning+", Bedding-Type: "+beddingType+", Breakfast: "+breakfast+", Kitchen-Facility: "+kitchenFacility+", Flooring: "+flooring+"]";
    }
}