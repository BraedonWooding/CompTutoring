package example;

public abstract class Shape {
    public String color;

    public Shape(String color) {
        System.out.println("Inside shape constructor");
        this.color = color;
    }

    public abstract int GetArea();

    public String GetColorName() {
        return this.color;
    }
}
