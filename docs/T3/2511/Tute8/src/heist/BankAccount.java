package heist;

/**
 * A bank account.
 *
 * @invariant balance >= 0
 *
 * @author Robert Clifton-Everest
 *
 */
public class BankAccount {

    private int balance;

    public BankAccount() {
        this.balance = 0;
    }

    /**
     * Deposit the given amount into the bank account.
     *
     * @precondition amount > 0
     * @postcondition balance = old balance + amount
     *
     * @param amount The amount of money to deposit.
     */
    public void deposit(int amount) {
        balance += amount;
    }

    /**
     * Withdraw the given amount from the account.
     *
     * @precondition amount > 0
     *
     * @param amount
     * @return True if withdrawal succeeded, false otherwise.
     */
    public boolean withdraw(int amount) {
        synchronized (this) {
            if (amount <= balance) {
                /*
                 * Thread 1 Thread 2 READ balance = 0 WRITES balance = 1 READ balance = 1 WRITES
                 * balance = 2 Final Value = Balance == 1 rather than 2
                 */

                balance -= amount;
                return true;
            }
            return false;
        }
    }

    /**
     * Get the balance of the account.
     * 
     * @return
     */
    public int getBalance() {
        return balance;
    }
}
