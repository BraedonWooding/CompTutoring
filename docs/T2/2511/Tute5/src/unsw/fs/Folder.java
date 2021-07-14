package unsw.fs;

import java.util.List;

public class Folder extends Inode {
    private List<Inode> contents;

    @Override
    public int getFileSize() {
        int sum = 0;
        int count = 0;
        for (Inode inode : contents) {
            if (inode instanceof File) {
                sum += inode.getFileSize();
                count++;
                if (count == 10) break;
            }
        }

        return contents.stream()
            .filter(i -> i instanceof File)
            .limit(10)
            .mapToInt(x -> x.getFileSize())
            .sum();
    }

    @Override
    public void processVisitor(Visitor v) {
        v.handleDirectory(this);
        for (Inode inode : contents) {
            inode.processVisitor(v);
        }
    }
}
