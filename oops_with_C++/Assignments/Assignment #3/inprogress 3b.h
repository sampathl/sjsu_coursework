#include <iostream>
#include <iomanip>

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/
using namespace std;
void do_spiral(const int n, const int start);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
}

void do_spiral(const int n, const int start)
{
	cout<< "Spiral of size "<< n << " starting at "<< start << endl;
if (n%2!=0)
{
int a1[n*n];
int Row_counter=0;
cout<< endl;
for (int i=0; i < (n*n); i++)
{
	a1[i] = (i+start);
}

for (int i=0; i < (n*n); i++)
{
	if (Row_counter == n) 		//print in the next row condition.
        {
           cout<<endl;
           Row_counter=0;
        }
	cout <<setw(4)<< a1[i];
	Row_counter = Row_counter+1;
}
cout << "\n\n";
}else if (n%2 == 0)
	cout << "***** Error: Size "<<n<< " must be odd." << endl<<endl;
}