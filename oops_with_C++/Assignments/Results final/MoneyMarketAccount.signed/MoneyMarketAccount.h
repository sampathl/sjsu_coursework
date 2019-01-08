/*
  The First National Bank of Stroustrup, in its unbounded generosity,
  gives 0.05% interest on the minimum monthly balance of its money
  market accounts. The first five transactions per month are free,
  as are all deposits of amounts exceeding $1000. Each further 
  transaction (deposit or withdrawal) incur a charge of $10. A balance
  inquiry does not count as a transaction.

  Complete the following class and its member functions. 
*/

class MoneyMarketAccount
{
private:
   double balance;

   // Add additional data members ...
public:
   /**
      Constructs an account with a zero balance.
   */
   MoneyMarketAccount();
   /**
      Gets the current balance.
   */
   double get_balance() const;
   /**
      Deposits the given amount and deducts any transaction fees.
      The amount is always > 0.
   */
   void deposit(double amount);
   /**
      Withdraws the given amount and deducts any transaction fees.
      The amount is always > 0.
   */
   void withdraw(double amount);
   /**
      Apply interest, reset month state.
   */
   void end_of_month();
};
