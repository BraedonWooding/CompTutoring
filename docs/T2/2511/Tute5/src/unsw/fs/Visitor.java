package unsw.fs;

public interface Visitor {
    public void handleFile(File f);
    public void handleDirectory(Folder d);
}
