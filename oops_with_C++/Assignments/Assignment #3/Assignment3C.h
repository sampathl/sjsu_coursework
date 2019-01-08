// Assignment 3c.
// Student Name: Sampath Lakkaraju.
// Student ID: 011818781.
// Student email: sampath.lakkaraju@sjsu.edu.
/* The program prints '#' for prime numbers and '.' for composite numbers from the center of the matrix in an anti clockwise spiral
	the program uses vector of vectors method. 
	the starting number and the size of the matrix are provided in the main.
	the starting number should not exceed 50 and greater than 0*/
	
#include <iostream>
#include <iomanip>
#include <vector>

const int MAX_START = 50;   // maximum starting number

using namespace std;

void do_prime_spiral(int n, int start);
/* Function takes in the starting number and size of the matrix and intialise the vector required to form the spiral
	@param n is the size of the matrix required provided in the main,
	@param start is the number at which the spiral has to start also provided in main,
	@param Prime_vec is a vector which contains the consecutive numbers,
	@param Spiral_vec is a vector of vectors into which spiral is arranged.*/
	
void compute_prime (vector<int>& Prime_vec, int size); 
/* Function checks if the given vector index is a prime number,
	if the index is not a prime changes the corresponding vector value to -2
	@ param Prime_id is an vector with all the valuse set to -1 initially
	@ param size is the size of the vector.*/

void make_spiral(vector<int>& Prime_vec,vector<vector<int>>& Spiral_vec, int n, int start);
/* Function arrangs the computed prime number identity from Prime_vec in a anticlockwise directional spiral into the vector of vectors Spiral_vec 
	@param x and y are the indices used for the vector of vectors Spiral_vec*/
	
void print_spiral(vector<vector<int>>& Spiral_vec, int n);
/* Function takes in the vector of vectors Spiral_vec and the size of the matrix and prints the '#' for prime numbers and '.' for composite numbers 
	in a matrix format the data in the vector is arranged in such a way that the a spiral emrges when the matrix is printed*/


int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);				// do_prime_spiral functions calls wit different inputs.
}

void do_prime_spiral(const int n, const int start)
{
	cout<< "Prime spiral of size "<< n << " starting at "<< start << endl;		// Output indicating the size ant starting value of spiral
	if ( start <=MAX_START && start >0)			// Condition to check if the start value is greater than the MAX_START size.
	{
		if (n%2!=0)						// condition to check if the the size of matrix is odd.
		{
			vector<int> Prime_vec; 	
			
			for (int i=0; i<((n*n)+(start)); i++) 	// Prime_vec vector values intialisation.
			{
				Prime_vec.push_back(-1);					// Array priliminary -1 assignment.
			}
			compute_prime (Prime_vec,((n*n)+(start)));		// Function call to compute prime numbers.
			
			vector < vector<int> > Spiral_vec;				// vector of vectors values initialisation.
			vector <int> temp_vector;
			
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
				{
					temp_vector.push_back(0);
				}
			Spiral_vec.push_back(temp_vector);
			temp_vector.clear();
			
			}
			
			make_spiral(Prime_vec,Spiral_vec, n, start);			// Calling the make_spiral function.
			print_spiral(Spiral_vec, n);					// Calling the print_spiral function.
			cout << "\n\n";
		}
		else if (n%2 == 0)							// Size of the matrix is not odd condition.
		cout << "***** Error: Size "<<n<< " must be odd." << endl<<endl;
	}
	else 											// Starting value provided is grater than MAX_START condition. 
	{
	cout << "***** Error: Starting value "  << start << " < 1 or > 50"<< endl<<endl;
	}
}

void compute_prime(vector<int>& Prime_vec,int size)
{
	Prime_vec[1]=-2;
    
	for (int i=2; i<size;i++)			// Loop for cheking all the numbers in an vector.
    {
        if (Prime_vec[i] == -1)		// Check to see if the number is composite or not. 
        {
            for (int j=(i*i); j<size;j=j+i)
            {
                Prime_vec[j]=-2;		// Composite number identification assignment.
            }
        }
    }
}
void make_spiral(vector<int>& Prime_vec,vector<vector<int>>& Spiral_vec, int n, int start)
{
	int x=0;					// Row index of vector of vectors.
	int y=0;					// Column index of vector of vectors. 
	int i=start;				// Counter for the spiral loop initialisation.
	char direction='r';				// Spiral direction variable.
	while (i<((n*n)+(start)))	// loop to complete the spiral. 
	{
		if (i== start)
		{
			x=((n/2));			// Starting position of the spiral. 
			y=((n/2));
			Spiral_vec[x][y]=Prime_vec[i];		// Starting value of the the spiral from Prime_vec array.
			i=i+1;				// number incrementer.
		}
	
		switch(direction) 			// Direction managment cases.  
		{
			case 'r'  :			// Right movement case.
			{
				if (Spiral_vec[x][y+1]!=0)		// Condition to check if the intended position is used or not.
				{
					direction='d';
				}
				if (Spiral_vec[x][y+1]==0)
				{
					y=y+1;				// Position index incrementer.
					Spiral_vec[x][y]=Prime_vec[i];
					i=i+1;
					direction='u';			// Direction assignment.
				}
			}
			break; //optional
			
			case 'u'  :			// Upward movement case.
			{
				if (Spiral_vec[x-1][y]!=0)
				{
					direction='r';
				}
				if (Spiral_vec[x-1][y]==0)
				{
					x=x-1;
					Spiral_vec[x][y]=Prime_vec[i];
					i=i+1;
					direction='l';
				}
			}
			break; //optional
			
			case 'l'  :			// Left movement case.
			{
				if (Spiral_vec[x][y-1]!=0)
				{
					direction='u';
				}
				if (Spiral_vec[x][y-1]==0)
				{
					y=y-1;
					Spiral_vec[x][y]=Prime_vec[i];
					i=i+1;
					direction='d';
				}
			}
			break; //optional
						
			case 'd'  :			// Down movement case.
			{
				if (Spiral_vec[x+1][y]!=0)
				{
					direction='l';
				}
				if (Spiral_vec[x+1][y]==0)
				{
					x=x+1;
					Spiral_vec[x][y]=Prime_vec[i];
					i=i+1;
					direction='r';
				}
			}
			break; //optional
		}	

	}
}
void print_spiral(vector<vector<int>>& Spiral_vec, int n)
{
int Row_counter=0;
cout<<endl;
for (int x=0; x < (n); x++)
{
	for (int y=0; y < (n); y++)
	{
		if (Row_counter == n) 		//print in the next row condition.
        {
           cout<<endl;
           Row_counter=0;
        }
		if (Spiral_vec[x][y]==-1)			// Prime number check using vector values.
        {
			cout<< setw(1) <<"#";				//Prime number print using vector index.
			Row_counter=Row_counter+1;
    
        } 
		else if (Spiral_vec[x][y]==-2)
		{
			cout<< setw(1) <<".";				//composite number print using vector index.
			Row_counter=Row_counter+1;
    
        } 
	}
}
}
