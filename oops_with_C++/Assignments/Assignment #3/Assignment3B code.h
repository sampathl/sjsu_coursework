// Assignment 3b.
// Student Name: Sampath Lakkaraju.
// Student ID: 011818781.
// Student email: sampath.lakkaraju@sjsu.edu.
/* The program prints continous numbers from the center of the matrix in an anti clockwise spiral
	the starting number and the size of the matrix are provided in the main 
	the starting number should not exceed 50 and the maximum size of the matrix is 101*/

#include <iostream>
#include <iomanip>

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

using namespace std;

void do_spiral(int n, int start);
/* Function takes in the starting number and size of the matrix and intialise the arrays required to form the spiral
	@param n is the size of the matrix required provided in the main,
	@param start is the number at which the spiral has to start also provided in main,
	@param number_ary is a one dimension array which contains the consecutive numbers,
	@param spiral_ary is a two dimentional array into which spiral is arranged.*/
	
void make_spiral(int number_ary[],int spiral_ary[][MAX_SIZE], int n);
/* Function arrangs the consequtive numbers from number_ary in a anticlockwise directional spiral into the two dimentional array spiral_ary 
	MAX_SIZE is the global constant(101) which limits of the size of the matrix 
	@param x and y are the indices of the two dimentional array spiral_ary*/
	
void print_spiral(int spiral_ary[][MAX_SIZE], int n);
/* Function takes in the array spiral_ary and the size of the matrix and prints the data in the array in a matrix format 
	the data in the array is arranged in such a way that the a spiral emrges when the matrix is printed*/


int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
	do_spiral(12, 13);
    do_spiral(15, 17);	 		// do_spiral functions calls wit different inputs.
}

void do_spiral(const int n, const int start) 
{
	cout<< "Spiral of size "<< n << " starting at "<< start << endl;		// Output indicating the size ant starting value of spiral
	if (start <= MAX_START && start > 0 )			// Condition to check if the start value is greater than the MAX_START size.
	{		
		if ( n <102 && n >0)		// Condition to check if the size of matrix is in between 1 and 101 inclusive.
		{
			if (n%2!=0)				// condition to check if the the size of matrix is odd.
			{
				int number_ary[n*n];		// maximum number of elements in a matrixof size n is (n*n).
				cout<< endl;
				for (int i=0; i < (n*n); i++)		// number_ary array values intialisation.
				{
					number_ary[i] = (i+start);				// considering the starting number provided in the main. 
				}
			
				int spiral_ary[n][MAX_SIZE];				// spiral_ary array values initialisation.
				for (int i=0;i<n;i++)
				{
					for (int j=0; j<n;j++)
					{
						spiral_ary[i][j]=0;
					}
				}
				
				make_spiral(number_ary,spiral_ary, n);			// Calling the make_spiral function.
				print_spiral(spiral_ary, n);			// Calling the print_spiral function.
				cout << "\n\n";
			}
			else if (n%2 == 0)				// Size of the matrix is not odd condition.
			cout << "***** Error: Size "<<n<< " must be odd." << endl<<endl;
		}
		else if (n >101 || n <0)			// Size of matrix provided is not inbetween 101 and 1 inclusive condition.
		{
			cout << "***** Error: size of matrix "  << n << " < 0 or > 101"<< endl<<endl;
		}
	}
	else if (start > MAX_START)				// Starting value provided is grater than MAX_START condition. 
	{
		cout << "***** Error: Starting value "  << start << " < 1 or > 50"<< endl<<endl;
	}
}

void make_spiral(int number_ary[],int spiral_ary[][MAX_SIZE], int n)
{
	int x=0;					// Row index of spiral_ary array.
	int y=0;					// Column index of spiral_ary array. 
	int i=0;					// Counter for the spiral loop initialisation.
	char direction='r';				// Spiral direction variable.
	while (i<(n*n))				// loop to complete the spiral. 
	{
		if (i==0)				
		{
			x=((n/2));
			y=((n/2));			// Starting position of the spiral. 
			spiral_ary[x][y]=number_ary[i];		// Starting value of the the spiral from number_ary array.
			i=i+1;				// number incrementer.
		}
	
		switch(direction) 			// Direction managment cases. 
		{
			case 'r'  :			// Right movement case.
			{
				if (spiral_ary[x][y+1]!=0)		// Condition to check if the intended position is used or not.
				{
					direction='d';
				}
				if (spiral_ary[x][y+1]==0)
				{
					y=y+1;				// Position index incrementer.
					spiral_ary[x][y]=number_ary[i];
					i=i+1;
					direction='u';			// Direction assignment.
				}
			}
			break; 
			
			case 'u'  :			// Upward movement case.
			{
				if (spiral_ary[x-1][y]!=0)
				{
					direction='r';
				}
				if (spiral_ary[x-1][y]==0)
				{
					x=x-1;
					spiral_ary[x][y]=number_ary[i];
					i=i+1;
					direction='l';
				}
			}
			break; 
			
			case 'l'  :			// Left movement case.
			{
				if (spiral_ary[x][y-1]!=0)
				{
					direction='u';
				}
				if (spiral_ary[x][y-1]==0)
				{
					y=y-1;
					spiral_ary[x][y]=number_ary[i];
					i=i+1;
					direction='d';
				}
			}
			break; 
						
			case 'd'  :			// Down movement case.
			{
				if (spiral_ary[x+1][y]!=0)
				{
					direction='l';
				}
				if (spiral_ary[x+1][y]==0)
				{
					x=x+1;
					spiral_ary[x][y]=number_ary[i];
					i=i+1;
					direction='r';
				}
			}
			break; 
		}	

	}
}

void print_spiral(int spiral_ary[][MAX_SIZE], int n)
{
	int Row_counter=0;					// Row_counter initializaion.
	for (int x=0; x < (n); x++)
	{
		for (int y=0; y < (n); y++)
		{
			if (Row_counter == n) 		//print in the next row condition.
			{
				cout<<endl;
				Row_counter=0;
			}
			cout <<setw(4)<< spiral_ary[x][y];		// Spiral print from the spiral_ary array.
			Row_counter = Row_counter+1;		
		}
	}
}
