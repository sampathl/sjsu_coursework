#include "MoneyMarketAccount.h"

MoneyMarketAccount::MoneyMarketAccount()
{
   balance = 0;
   
}

int count=0;
int min=0;
/**
   Gets the current balance.
*/
double MoneyMarketAccount::get_balance() const
{
   return balance;
}

/**
   Deposits the given amount and deducts any transaction fees.
*/
void MoneyMarketAccount::deposit(double amount)
{
   
   balance += amount;
   if (amount <= 1000)
   {
         if(count>4)
  
    	  balance-=10;
    	  
     count++;    
   
   }
   
   
}

/**
   Withdraws the given amount and deducts any transaction fees.
*/
void MoneyMarketAccount::withdraw(double amount)
{
   balance -= amount;
   if(count>4)
	{
		balance-=10;
	}
	if(balance<min)
	min=balance;
	
   count++;
   
}

/**
   Apply interest, reset month state.
*/
void MoneyMarketAccount::end_of_month()
{
   balance += min * 0.005; // 0.5 percent
   count=0;
   min=balance;
}
