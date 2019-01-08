// Assignment 3a
// Student Name: Sampath Lakkaraju.
// Student ID: 011818781.
// Student email: sampath.lakkaraju@sjsu.edu.
/* Program computes the prime numbers under 1000 using a onedimensional array
	the program uses the Sieve of Eratosthenes methode to compute athe prime numbers 
	the output displays all the prime numbers with 20 numbers in a row and "Done!" once all the numbers rare listed*/

#include <iostream>
#include<iomanip>

using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

void compute_prime (char Prime_id[], int size); 
/* Function checks if the given array index is a prime number,
 if the index is not a prime changes the corresponding array value to true
 @ param Prime_id is an array with all the valuse set to true initially
 @ param size is the size of the array.*/

void print_prime(char Prime_id[], int size);
/* Prints the prime numbers from 2 to MAX_NUMBER using the array 
	Prime_id index as the number and its value for prime number identification
	@ Row_counter is the counter for the number of prime numbers printed in the row.*/
	
/* The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{
    char Prime_id[MAX_NUMBER] ; // Array of size MAX_NUMBER.
    for (int i=0; i<MAX_NUMBER; i++) // Loop for array priliminary true assignment.
    {
        Prime_id[i]= 'a';		
    }
    
   for (int i=2; i<size;i++)			// Loop for cheking all the numbers in an array.
    {
        if (Prime_id[i] == 'a')		// Check to see if the number is composite or not. 
        {
            for (int j=(i*i); j<size;j=j+i)
            {
                Prime_id[j]='b';		// Composite number identification assignment.
            }
        }
    }
	
    print_prime(Prime_id,MAX_NUMBER);
}


void print_prime(char Prime_id[], int size)
{
    int Row_counter=0;					// Row_counter initializaion.
      for (int i=2; i<size; i++)		// Loop for array check.
    {
        if (Row_counter==ROW_SIZE) 		//print in the next row condition.
        {
           cout<<endl;
           Row_counter=0;
        }
        if (Prime_id[i]=='a')			// Prime number check using array values.
        {
        cout<< setw(4) <<i;				//Prime number print using array index.
        Row_counter=Row_counter+1;
    
        }    
    }
	cout << "\n\n" <<"Done!"; 
}