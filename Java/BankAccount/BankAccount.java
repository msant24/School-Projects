package BankAccount;

/**
 * A bank account has a balance that can be changed by deposits and withdrawals.
 */
public abstract class BankAccount
{  
   // instance var
   private double balance ;
   
   /**
      Constructs a bank account with a zero balance
   */
   public BankAccount()
   {  
      balance = 0;
   }

   /**
      Constructs a bank account with a given balance
      @param initialBalance the initial balance
   */
   public BankAccount(final double initialBalance) {
      balance = initialBalance;
   }

   /**
    * Deposits money into the bank account.
    * 
    * @param amount the amount to deposit
    */
   public void deposit(final double amount) {
      balance = balance + amount;
   }

   /**
    * Withdraws money from the bank account.
    * 
    * @param amount the amount to withdraw
    */
   public void withdraw(final double amount) {
      balance = balance - amount;
   }

   /**
    * Gets the current balance of the bank account.
    * 
    * @return the current balance
    */
   public double getBalance() {
      return balance;
   }

   /**
    * Transfers money from the bank account to another account
    * 
    * @param other  the other account
    * @param amount the amount to transfer
    */
   public void transfer(final BankAccount other, final double amount)
   {  
      withdraw(amount);
      other.deposit(amount);
   }
}