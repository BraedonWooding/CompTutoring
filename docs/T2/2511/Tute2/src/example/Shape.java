package example;

public class Shape {
    private String color;

    public String GetColor() {
        return this.color;
    }

    public int GetArea() {
        return 0;
    }

    public static Shape GetRedShape() {
        return new Shape("red");
    }

    public Shape(String color) {
        System.out.println("Inside Shape constructor");
        this.color = color;
    }

    public static void main(String[] args) {
        Shape redShape = Shape.GetRedShape();
    }
}
