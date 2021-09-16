package shouter;

public class Shouter {
    private String msg;

    public Shouter(String msg) {
        this.msg = msg;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    public void shout() {
        System.out.println(msg.toUpperCase());
    }

    public static void main(String[] args) {
        Shouter shouter = new Shouter("Hello World");
        shouter.shout();
        shouter.setMsg("Other msg");
    }
}
