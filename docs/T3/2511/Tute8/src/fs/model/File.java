package fs.model;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class File extends Inode {
    public File(Path path) {
        super(path);
    }

    public String getIcon(boolean expanded) {
        return "text-x-generic.png";
    }
}
