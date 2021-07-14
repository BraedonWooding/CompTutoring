package unsw.fs;

public abstract class Inode {
    private String name;
    private Inode parent;

    public abstract int getFileSize();
    public abstract void processVisitor(Visitor v);
}
