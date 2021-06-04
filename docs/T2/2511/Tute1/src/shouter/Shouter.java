package shouter;

public class Shouter {
    private String message;
    private static String name = "Braedon";

    public Shouter(String message) {
        this.message = message;
    }

    public String getMessage() {
        return this.message;
    }

    public void whisper() {
        System.err.println(this.message.toLowerCase());
    }

    public void shouter() {
        System.err.println(this.message.toUpperCase());
    }

    public static void main(String[] args) {
        Shouter shouter = new Shouter("Hello World!");
        shouter.whisper();
        shouter.shouter();
    }
}
