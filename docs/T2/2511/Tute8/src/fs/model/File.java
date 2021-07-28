package fs.model;

import java.nio.file.Path;

public class File extends Inode {
    private static String fileImage = "text-x-generic.png";

    public File(Path path) {
        super(path);
    }

    @Override
    public String getIconName(boolean isExpanded) {
        return fileImage;
    } 
}
