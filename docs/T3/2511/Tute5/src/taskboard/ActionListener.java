package taskboard;

import taskboard.state.State;

public interface ActionListener {
    public default void onCardMoved(Card card, State previousState) {}
    public default void onValidationFailed(Card card, Validation validation) {}
    public default void onValidationAttempted(Card card, Validation validation) {}
    public default Validation externalValidation(Card card) { return Validation.Ok(); }
}
