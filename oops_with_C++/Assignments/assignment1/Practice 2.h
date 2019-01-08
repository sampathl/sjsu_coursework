#include <iostream>
using namespace std;

int main()
{   
   cout << "n: " << endl;
   int n;
   cin >> n;
   cout << "d: " << endl;
   int d;
   cin >> d;
   int result = 0;
   int x=0;
   int a=d;
   if (d==0) {
	x=1;
	}else
	{
		while (a!=0)
		{
			x=x+1;
			a=a/10;
		}
	}
	
	int y=10;
    
		while (x>1)
		{
		y=y*10;
		x=x-1;
		}
	
   while (n!=0)
   {
       int r = 10;
       r = n% y;   
        if (r == d)
        { 
            result = result + 1;
        }
        n = n/10;
   }
   cout << "Count: " << result << endl;
   return 0;
}
