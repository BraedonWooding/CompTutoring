package shouter;

public class Shouter {
    private String msg;

    public Shouter(String msg) {
        this.msg = msg;
    }

    public String getMsg() {
        return this.msg;
    }
    
    public void setMsg(String msg) {
        this.msg = msg;
    }

    public void whisper() {
        System.out.println(msg.toLowerCase());
    }

    public void shout() {
        System.out.println(msg.toUpperCase());
    }

    public static void main(String[] args) {
        Shouter myShout = new Shouter("Comp2511");
        myShout.shout();
        myShout.whisper();

        myShout.setMsg("Yayyy");
        myShout.shout();
        myShout.whisper();
    }
}