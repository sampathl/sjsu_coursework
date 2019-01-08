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

cout<< endl;
for (int i=0; i < (n*n); i++)
{
	a1[i] = (i+start);
}

int a2[n][n];
for (int i=0;i<n;i++)
{
	for (int j=0; j<n;j++)
	{
		a2[i][j]=0;
	}
}

int x=0;
int y=0;
int i=0;
char dir='r';
while (i<(n*n))
{
	if (i==0)
	{
		x=((n/2));
		y=((n/2));
		a2[x][y]=a1[i];
		i=i+1;
	}

switch(dir) {
   case 'r'  :
    {
		if (a2[x][y+1]!=0)
		{
		dir='d';
		}
		if (a2[x][y+1]==0)
		{
			y=y+1;
			a2[x][y]=a1[i];
			i=i+1;
			dir='u';
		}
	}
      break; //optional
   case 'u'  :
    {
		if (a2[x-1][y]!=0)
		{
		dir='r';
		}
		if (a2[x-1][y]==0)
		{
			x=x-1;
			a2[x][y]=a1[i];
			i=i+1;
			dir='l';
		}
	}
      break; //optional
	  
	case 'l'  :
    {
		if (a2[x][y-1]!=0)
		{
		dir='u';
		}
		if (a2[x][y-1]==0)
		{
			y=y-1;
			a2[x][y]=a1[i];
			i=i+1;
			dir='d';
		}
	}
      break; //optional
	  
	case 'd'  :
    {
		if (a2[x+1][y]!=0)
		{
		dir='l';
		}
		if (a2[x+1][y]==0)
		{
			x=x+1;
			a2[x][y]=a1[i];
			i=i+1;
			dir='r';
		}
	}
      break; //optional

}




	
}
int Row_counter=0;
for (int x=0; x < (n); x++)
{
	for (int y=0; y < (n); y++)
	{
		if (Row_counter == n) 		//print in the next row condition.
        {
           cout<<endl;
           Row_counter=0;
        }
		cout <<setw(4)<< a2[x][y];
		Row_counter = Row_counter+1;
	}
}
cout << "\n\n";
}else if (n%2 == 0)
	cout << "***** Error: Size "<<n<< " must be odd." << endl<<endl;
}

