package shouter;

public class BankAccount {
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    public int getBalance() {
        return balance;
    }

    public Request withdrawlRequest(int amount) {
        if (balance > amount) {
            return new Request(this, amount);
        } else {
            return null;
        }
    }

    public boolean performRequest(Request request) {
        if (request.from.getBalance() > request.getAmount()) {
            request.from.balance -= request.getAmount();
            this.balance += request.getAmount();
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        BankAccount braedon = new BankAccount(1000);
        BankAccount clone = new BankAccount(10000);
        
        Request request = braedon.withdrawlRequest(1000);
        clone.performRequest(request);
    }

    public class Request {
        private BankAccount from;
        private int amount;

        public Request(BankAccount from, int amount) {
            this.from = from;
            this.amount = amount;
        }

        public int getAmount() {
            return amount;
        }
    }
}
