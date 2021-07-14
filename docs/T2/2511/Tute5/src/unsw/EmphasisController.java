package unsw;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class EmphasisController {
    @FXML
    private TextField text;

    private Emphasis emphasis = new Emphasis();

    @FXML
    public void handleEmphasise(ActionEvent event) {
        emphasis.emphasise();
    }

    @FXML
    public void initialize() {
        text.textProperty().bindBidirectional(emphasis.getProperty());
    }
}
