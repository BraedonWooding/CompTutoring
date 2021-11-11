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
        return !(inode instanceof Expandable);
    }

    public FilePathTreeItem(Inode inode) {
        super(inode.getPath().toString());
        this.inode = inode;

        this.setGraphic(new ImageView(new Image(ClassLoader.getSystemResourceAsStream("fs/resources/" + inode.getIcon(false)))));
        this.setValue(String.format("%s (%f KiB)", inode.getName(), inode.getFileSize() / 1024.0));

        addEventHandler(TreeItem.<String>branchExpandedEvent(), (ev) -> {
            ImageView iv = (ImageView) getGraphic();
            iv.setImage(new Image(ClassLoader.getSystemResourceAsStream("fs/resources/" + inode.getIcon(true))));

            if (inode instanceof Expandable) {
                Expandable e = (Expandable)inode;
                for (Inode childInode : e.expand()) {
                    this.getChildren().add(new FilePathTreeItem(childInode));
                }
            }
        });

        addEventHandler(TreeItem.<String>childrenModificationEvent(), (ev) -> {
            this.setValue(String.format("%s (%f KiB)", inode.getName(), inode.getFileSize() / 1024.0));
        });

        this.addEventHandler(TreeItem.<String>branchCollapsedEvent(), (ev) -> {
            ImageView iv = (ImageView) getGraphic();
            iv.setImage(new Image(ClassLoader.getSystemResourceAsStream("fs/resources/" + inode.getIcon(false))));
        });
    }
}
