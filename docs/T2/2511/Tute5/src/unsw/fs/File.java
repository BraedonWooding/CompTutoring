package unsw.fs;

public class File extends Inode {

    @Override
    public int getFileSize() {
        return 42;
    }

    @Override
    public void processVisitor(Visitor v) {
        v.handleFile(this);
    }
    
}
