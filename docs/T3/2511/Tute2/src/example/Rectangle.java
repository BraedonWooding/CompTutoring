package example;

public class Rectangle extends Shape {
    public int height;
    public int width;

    public Rectangle(String color) {
        super(color);
        System.out.println("Inside Rectangle constructor with one argument");
    }

    public Rectangle(String name, int width, int height) {
        this(name);
        this.width = width;
        this.height = height;
        System.out.println("Inside Rectangle constructor with three arguments");
    }

    @Override()
    public int GetArea() {
        return this.width * this.height;
    }

    public int GetHeight() {
        return this.height;
    }

    public static void main(String[] args) {
        Rectangle r = new Rectangle("red", 10, 20);
        System.out.println(r.GetArea());
        Shape s = r;
        System.out.println(s.GetArea());
        Rectangle r2 = (Rectangle)s;
        System.out.println(r2.GetArea());
    }
}
