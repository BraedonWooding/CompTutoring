package fs.model;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public abstract class Inode {
    private Path path;
    private long fileSize;

    public Inode(Path path) {
        this.path = path;
        try {
            this.fileSize = Files.size(path);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public abstract String getIconName(boolean isExpanded);

    public long getFileSize() {
        return fileSize;
    }

    public Path getPath() {
        return path;
    }

    @Override
    public String toString() {
        String fullPath = path.toString();
        if (!fullPath.endsWith(java.io.File.separator)) {
            // set the value (which is what is displayed in the tree)
            int indexOf = fullPath.lastIndexOf(java.io.File.separator);
            if (indexOf > 0) {
                fullPath = fullPath.substring(indexOf + 1);
            }
        }
        return fullPath + " (" + getFileSize() / 1024 + " KiB)";
    }
}
