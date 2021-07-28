package fs.model;

import java.io.IOException;
import java.util.List;

public interface Expandable {
    public List<Inode> expand() throws IOException;
}
