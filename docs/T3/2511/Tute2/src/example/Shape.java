package example;

public abstract class Shape {
    private String color;

    public Shape(String color) {
        System.out.println("Inside shape constructor");
        this.color = color;
    }

    public String GetColorName() {
        return this.color;
    }
    
    public abstract int GetArea();
}
