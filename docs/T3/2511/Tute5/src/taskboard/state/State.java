package taskboard.state;

import taskboard.Validation;

public abstract class State {
    private String assignee;
    private int totalTimeEstimation;
    private int totalTimeSpent;

    public State(String assignee, int totalTimeEstimation, int totalTimeSpent) {
        this.setAssignee(assignee);
        this.totalTimeEstimation = totalTimeEstimation;
        this.totalTimeSpent = totalTimeSpent;
    }

    public String getAssignee() {
        return assignee;
    }

    public void setAssignee(String assignee) {
        this.assignee = assignee;
    }

    public int timeLeft() {
        return totalTimeEstimation - totalTimeSpent;
    }

    public void spendTime(int hrs) {
        this.totalTimeSpent += hrs;
    }

    public int getTimeSpent() {
        return totalTimeSpent;
    }

    public int getEstimation() {
        return totalTimeEstimation;
    }

    protected void setEstimation(int hrs) {
        this.totalTimeEstimation = hrs;
    }

    public abstract Validation isValid(Object param);
    protected abstract State nextState(Object param);

    public State attemptToMoveCard(Object parameter) {
        Validation result = isValid(parameter);

        if (result.isOk()) {
            return nextState(parameter);
        } else {
            return this;
        }
    }
}
