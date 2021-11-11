package fs.model;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public abstract class Inode {
    private Path path;

    public Inode(Path path) {
        this.path = path;
    }

    public Path getPath() {
        return path;
    }

    public long getFileSize() {
        try {
            return Files.size(path);
        } catch (IOException e) {
            // presume file system is reasonable, and won't throw an exception
            return 0;
        }
    }

    public String getName() {
        if (path == null || path.getFileName() == null) return "";

        return path.getFileName().toString();
    }

    public abstract String getIcon(boolean expanded);
}
