package unsw;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class Emphasis {
    private StringProperty text = new SimpleStringProperty();

    public StringProperty getProperty() {
        return text;
    }

    public void emphasise() {
        this.text.set(this.text.get().toUpperCase());
    }
}
