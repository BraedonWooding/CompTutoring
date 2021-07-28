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
    private static String folderCollapseImage = "folder.png";
    private static String folderExpandImage = "folder-open.png";
    private List<Inode> children = new ArrayList<>();

    public Directory(Path path) {
        super(path);
    }

    @Override
    public String getIconName(boolean isExpanded) {
        return isExpanded ? folderExpandImage : folderCollapseImage;
    }

    @Override
    public List<Inode> expand() throws IOException {
        if (children.size() > 0) return Arrays.<Inode>asList();

        BasicFileAttributes attribs = Files.readAttributes(getPath(), BasicFileAttributes.class);
        if (attribs.isDirectory()) {
            DirectoryStream<Path> dir = Files.newDirectoryStream(getPath());
            for (Path innerFile : dir) {
                children.add(
                    innerFile.toFile().isDirectory()
                    ? new Directory(innerFile)
                    : new File(innerFile)
                );
            }
        }
        return children;
    }

    @Override
    public long getFileSize() {
        return super.getFileSize()
            + children.stream()
                .mapToLong(Inode::getFileSize)
                .sum();
    }
}
