package BuilderPattern;
public class RoomBuilder {
    int capacity;
    String airConditioning;
    String beddingType;
    String breakfast;
    String kitchenFacility;
    String flooring;
    String lightning;

    public RoomBuilder setCapacity(int capacity){
        this.capacity = capacity;
        return this;
    }
    public RoomBuilder setAirConditioning(String airConditioning){
        this.airConditioning = airConditioning;
        return this;
    }
    public RoomBuilder setBeddingType(String beddingType){
        this.beddingType = beddingType;
        return this;
    }
    public RoomBuilder setBreakfast(String breakfast){
        this.breakfast = breakfast;
        return this;
    }
    public RoomBuilder setKitchenFacility(String kitchenFacility){
        this.kitchenFacility = kitchenFacility;
        return this;
    }
    public RoomBuilder setFlooring(String flooring){
        this.flooring = flooring;
        return this;
    }
    public RoomBuilder setLightning(String lightning){
        this.lightning = lightning;
        return this;
    }

    public room getRoom(){
        return new room(capacity, airConditioning, beddingType, breakfast, kitchenFacility, flooring, lightning);
    }
}