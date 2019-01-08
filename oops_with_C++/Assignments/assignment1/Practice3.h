# include <iostream>
using namespace std;

int main()
{
	cout << "n: " << endl ;
	long int n;
	cin >> n ;
	long int n1=n;
	int d=0;
	int r=0;
	int counter=0;
	int r1=0;
	long int n2=n;
	int count2=0;
	
	
	while (n1!=0)
	{
		d=d+1;
		n1=n1/10;
	}
	int d1=d;
	int d2=d;
	n1=n;
	
	while (d1!=0)
	{
		r=n1%10;
		while (d2!=0)
		{
			r1=n2%10;
			if (r1==r)
				{ counter=counter+1;}
			d2=d2-1;
			n2=n2/10;
		}
		n2=n;
		d2=d;
		if (counter> count2)
			{
			count2= counter;
			}
		counter=0;
		d1=d1-1;
		n1=n1/10;
	}	
	cout << "count: " << count2 << endl;
}