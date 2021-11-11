package fs.model;

import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Directory extends Inode implements Expandable {
    private List<Inode> innerNodes = new ArrayList<>();

    public Directory(Path path) {
        super(path);
    }

    @Override
    public long getFileSize() {
        return super.getFileSize() + innerNodes.stream().mapToLong(Inode::getFileSize).sum();
    }

    public String getIcon(boolean expanded) {
        return expanded ? "folder-open.png" : "folder.png";
    }

    @Override
    public List<Inode> expand() {
        try {
            if (innerNodes.size() == 0) {
                DirectoryStream<Path> dir;
                dir = Files.newDirectoryStream(getPath());
                for (Path innerFile : dir) {
                    innerNodes.add(Files.isDirectory(innerFile) ? new Directory(innerFile) : new File(innerFile));
                }

                return innerNodes;
            }
        } catch (IOException e) {
        }

        return Arrays.<Inode>asList();
    }
}
