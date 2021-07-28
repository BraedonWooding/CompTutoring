package fs.ui;

import java.io.File;
import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.BasicFileAttributes;

import fs.model.Directory;
import fs.model.Expandable;
import fs.model.Inode;
import javafx.scene.control.TreeItem;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class FilePathTreeItem extends TreeItem<String> {
    private Inode inode;

    @Override
    public boolean isLeaf() {
        return !(inode instanceof Directory);
    }

    private Image getIcon(boolean isExpanded) {
        return new Image(ClassLoader.getSystemResourceAsStream("fs/resources/" + inode.getIconName(isExpanded)));
    }

    public FilePathTreeItem(Inode inode) {
        super(inode.toString());
        this.inode = inode;

        this.setGraphic(new ImageView(getIcon(false)));
        this.setValue(inode.toString());

        addEventHandler(TreeItem.<String>childrenModificationEvent(), (ev) -> {
            this.setValue(inode.toString());
        });

        addEventHandler(TreeItem.<String>branchExpandedEvent(), (ev) -> {
            ImageView iv = (ImageView)getGraphic();
            iv.setImage(getIcon(true));

            if (inode instanceof Expandable) {
                try {
                    for (Inode inner : ((Expandable)inode).expand()) {
                        getChildren().add(new FilePathTreeItem(inner));
                    }
                } catch (IOException x) {
                    x.printStackTrace();
                }
            }
        });

        this.addEventHandler(TreeItem.<String>branchCollapsedEvent(), (ev) -> {
            ImageView iv = (ImageView) getGraphic();
            iv.setImage(getIcon(true));
        });
    }
}
