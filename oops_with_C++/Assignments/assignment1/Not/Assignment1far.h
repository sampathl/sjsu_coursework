#include <iostream>
using namespace std;

int main()
{   
   cout << "Po: " << endl;
   int Po;
   cin >> Po;
   int P=Po;
   int S=0;
   int F=3;
   int Fp=0;
   int Ts=0;
   int Su=0;
   int Cu=0;
		cout << "Where\t   Cum. steps  Water amt.  Cum. step-units"<< endl;
		cout << "---------  ----------  ----------  ---------------\n" ;
	while (P>0)
	{
		if (F>0)
		{
			if(Fp==0)
			{
				S=P;
				Ts=Ts+S;
				Su=(S*F);
				Cu=Cu+Su;
				Fp=P;
				
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
			S=1;
			Ts=Ts+S;
			Su=(S*F);
			Cu=Cu+Su;
			Fp=Fp-1;
			P=P-1;
			
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
			S=P;
			Su=(S*F);
			Fp=0;
			Ts=Ts+S;
			Cu=Cu+Su;
			
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
				P = P-1;
		}
	}
return (0);

}