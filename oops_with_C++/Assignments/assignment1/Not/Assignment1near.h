#include <iostream>
using namespace std;

int main()
{   
   cout << "Po: " << endl;
   int Po;
   cin >> Po;
   int P=0;
   int S=0;
   int F=3;
   int Fp=0;
   int Ts=0;
   int Su=0;
   int Cu=0;
		cout << "Where\t   Cum. steps  Water amt.  Cum. step-units"<< endl;
		cout << "---------  ----------  ----------  ---------------\n" ;

	while (P<Po)
	{
		
		if (F>0)
		{
			S=1;
			Su=(S*F);
			Fp=Fp+1;
			Ts=Ts+S;
			Cu=Cu+Su;
			P=P+1;
			
			if (Fp>0)
				{cout <<"Plant  "<< P<< "      ";
				}
				else if (Fp==0)
				{
					cout<< "FAUCET        ";
				}
				
				if (Ts<=9 && Cu<=9)
				{cout<<" "<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";;
				}
				else if (Ts>9 && Cu<=9)
				{
					cout<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";
				}
				else if (Ts<=9 && Cu>9)
				{
					cout<<" " << Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}
				else if (Ts>9 && Cu>9)
				{
					cout<< Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}

			F=F-1;
		}
		else if ( F==0)
		{
			S=Fp;
			Su= (S*F);
			Fp=0;
			Ts=Ts+S;
			
			if (Fp>0)
				{cout <<"Plant  "<< P<< "      ";
				}
				else if (Fp==0)
				{
					cout<< "FAUCET        ";
				}
				
				if (Ts<=9 && Cu<=9)
				{cout<<" "<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";;
				}
				else if (Ts>9 && Cu<=9)
				{
					cout<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";
				}
				else if (Ts<=9 && Cu>9)
				{
					cout<<" " << Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}
				else if (Ts>9 && Cu>9)
				{
					cout<< Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}
				
				F=3;
				S=P;
				Ts=Ts+S;
				Su=(S*F);
				Cu=Cu+Su;
				Fp=P;
		}
	}
if (P==Po)
{
    S=P;
    Ts=Ts+S;
    Su=(S*F);
    Cu=Cu+Su;
	Fp=0;
	P=0;
	if (Fp>0)
				{cout <<"Plant  "<< P<< "      ";
				}
				else if (Fp==0)
				{
					cout<< "FAUCET        ";
				}
				
				if (Ts<=9 && Cu<=9)
				{cout<<" "<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";;
				}
				else if (Ts>9 && Cu<=9)
				{
					cout<< Ts<<"\t   "<<F<<" \t\t "<<Cu<<"\n";
				}
				else if (Ts<=9 && Cu>9)
				{
					cout<<" " << Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}
				else if (Ts>9 && Cu>9)
				{
					cout<< Ts<<"\t   "<<F<<"\t\t"<<Cu<<"\n";
				}
}
				return (0);

}
