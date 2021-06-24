package unsw.quaint.strategies;

import java.io.File;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.layout.VBox;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import unsw.quaint.state.State;
import unsw.quaint.tools.Tool;

/**
 * @author Braedon Wooding.
 */
public class ImagePlaceStrategy implements IShapeStrategy {
    private Image img;

    public static Tool GetTool() {
        return new Tool(new ImagePlaceStrategy(), "../imgs/img.png", "Place some images", "Image");
    }

    @Override
    public void dragDrawOnContext(GraphicsContext context, double topLeftX, double topLeftY, double width,
            double height, boolean isGhost) {
        context.drawImage(img, topLeftX, topLeftY, width, height);
    }

    @Override
    public void addWidgets(State state, VBox box) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Open Image");
        fileChooser.setSelectedExtensionFilter(new ExtensionFilter("Image Files", ".png"));
        File file = fileChooser.showOpenDialog(box.getScene().getWindow());
        if (file != null) {
            img = new Image(file.toURI().toString());
        }
    }
}
