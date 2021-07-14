package unsw.quaint.strategies;

import javafx.scene.layout.VBox;
import unsw.quaint.state.State;

/**
 * @author Braedon Wooding.
 */
public interface IToolStrategy {
    public default void initialiseTool(State state, VBox box) {}
}
