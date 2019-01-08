#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int Plan_Near( int, int);
int Plan_Far( int, int);
void Plan_Can_format_output(int, int);
void Can_position_output_details(int, int, int, int, int);
void Plan_comparision_output(int, int, int);

using namespace std;

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt"; 
	int plant_count;		//Plant_count declaration.
	
    ifstream input; 				//Inputstream declaration.
    input.open(INPUT_FILE_NAME);
	
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
	do
    {
		input >> plant_count; 	//Plant_count input from file.
   		
		if (plant_count== 0)	//No plant condition.
			{
				return 0;
			}
		// Variable declartions.
		int Cumi_Step_units_near=0;
		int Cumi_Step_units_far=0;
		int Plan_no;
		
		// Near plan.
		Plan_no=1;
		Plan_Can_format_output(Plan_no, plant_count );
		Cumi_Step_units_near=Plan_Near(UNITS_PER_CAN, plant_count);

		// Plan Far
		Plan_no=2;
		Plan_Can_format_output(Plan_no, plant_count);
		Cumi_Step_units_far=Plan_Far(UNITS_PER_CAN, plant_count);
		
		Plan_comparision_output(plant_count,Cumi_Step_units_near,Cumi_Step_units_far);
		
	} while (plant_count > 0);
    
    return 0;
}

int Plan_Near( int UNITS_PER_CAN, int plant_count)
{
	int Plant_no=0;
		int Steps_can_takes=0;
		int Water_amt_can=UNITS_PER_CAN;
		int Can_posit=0;
		int Cumi_Steps=0;
		int Cumi_Step_units=0;
		while (Plant_no < plant_count)		// Loop for Trip
		{
			if (Water_amt_can>0)					// Can water check.
				{
					Steps_can_takes=1;
					Can_posit=Can_posit+1;						//Can position incriment
					Cumi_Steps=Cumi_Steps+Steps_can_takes;		//Cumulative steps computation.
					Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);	//Cumulative step unit computation.
					Plant_no=Plant_no+1;			//Number of plant filled.
					
					Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
				
					Water_amt_can=Water_amt_can-1;	// Can water level decrement.
				}
			else if ( Water_amt_can==0)				// Can water refill loop.
				{
					Steps_can_takes=Can_posit;		// Steps the can is away from faucet.
					Can_posit=0;					//Faucet considerd as 0 step.
					Cumi_Steps=Cumi_Steps+Steps_can_takes;
					Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
					
					Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
						
					Water_amt_can=UNITS_PER_CAN;		//Can refill assignment.
					Steps_can_takes=Plant_no;
					Cumi_Steps=Cumi_Steps+Steps_can_takes;
					Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
					Can_posit=Plant_no;
				}
		}
		
		if (Plant_no==plant_count)					// Can return to start position.
			{
				Steps_can_takes=Plant_no;
				Cumi_Steps=Cumi_Steps+Steps_can_takes;
				Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
				Can_posit=0;
				Plant_no=0;
				
				Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
			}
		
		//Cumi_Step_units_near=Cumi_Step_units;			//Cumulative step per units assign for plan near.
	
		cout << endl<< "Plan Near: Total steps = "<< Cumi_Steps << ", total step-units = "<< Cumi_Step_units<<" \n";
		
		return (Cumi_Step_units);
}

int Plan_Far( int UNITS_PER_CAN, int plant_count)
{
		int Plant_no=plant_count;
		int Steps_can_takes=0;
		int Water_amt_can=UNITS_PER_CAN;
		int Can_posit=0;
		int Cumi_Steps=0;
		int Cumi_Step_units=0;
		
		while (Plant_no>0)				// Loop for Plant counter.
		{
			if (Water_amt_can>0)				// Faucet water check.
				{
					if(Can_posit==0)				
						{
							Steps_can_takes=Plant_no;	// Steps to be taken for reaching last plant.
							Cumi_Steps=Cumi_Steps+Steps_can_takes;
							Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
							Can_posit=Plant_no;
							
							Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
							
							Water_amt_can=Water_amt_can-1;
						}
					
					// Steps taken from far when faucet is filled.
					
					Steps_can_takes=1;		
					Cumi_Steps=Cumi_Steps+Steps_can_takes;
					Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
					Can_posit=Can_posit-1;
					Plant_no=Plant_no-1;
					
					Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
						
					Water_amt_can=Water_amt_can-1;
				}
			else if ( Water_amt_can==0)
				{
					Steps_can_takes=Plant_no;
					Can_posit=0;
					Cumi_Steps=Cumi_Steps+Steps_can_takes;
					Cumi_Step_units=Cumi_Step_units+(Steps_can_takes*Water_amt_can);
					
					Can_position_output_details(Can_posit, Plant_no, Cumi_Steps, Cumi_Step_units, Water_amt_can);
						
					Water_amt_can=UNITS_PER_CAN;				//Can refill.
					Plant_no = Plant_no-1;
				}
		}
		
		//Cumi_Step_units_far = Cumi_Step_units;				//Cumulative step units in far plan.
		
		cout << endl<<"Plan Far: Total steps = "<< Cumi_Steps << ", total step-units = "<< Cumi_Step_units<<" \n";
        
		return (Cumi_Step_units);
	
}

void Plan_Can_format_output(int a, int plant_count)
{
	if (a==1)
	{
		 cout << endl;
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
        cout << endl;
	} 
	else if (a==2)
	{
		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
	}
	
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

}

void Can_position_output_details(int a, int b, int c, int d, int e)
{
	
	int Can_posit= a;
	int Plant_no=b;
	int Cumi_Steps=c;
	int Cumi_Step_units=d;
	int Water_amt_can=e;
	
	if (Can_posit>0)								// Output of can position.
		{
			cout <<"Plant  "<< Plant_no<< "      ";	// If the can position is at plant 
		}
	else if (Can_posit==0)
		{
			cout<< "FAUCET        ";				// If the can position is at faucet
		}
	
			// Output of Details
	
	if (Cumi_Steps<=9 && Cumi_Step_units<=9)	// if Cumulative Steps and Cumulative Step per units are single digit.
		{
			cout<<" "<< Cumi_Steps<<"\t   "<<Water_amt_can<<" \t\t "<<Cumi_Step_units<<"\n";;
		}
	else if (Cumi_Steps>9 && Cumi_Step_units<=9)	// if Cumulative Steps is double digit.
		{
			cout<< Cumi_Steps<<"\t   "<<Water_amt_can<<" \t\t "<<Cumi_Step_units<<"\n";
		}
	else if (Cumi_Steps<=9 && Cumi_Step_units>9)	// if Cumulative Step per units is double digit.
		{
			cout<<" " << Cumi_Steps<<"\t   "<<Water_amt_can<<"\t\t"<<Cumi_Step_units<<"\n";
		}
	else if (Cumi_Steps>9 && Cumi_Step_units>9)	// if Cumulative Steps and Cumulative Step per units are double digit.
		{
			cout<< Cumi_Steps<<"\t   "<<Water_amt_can<<"\t\t"<<Cumi_Step_units<<"\n";
		}
	
}

void Plan_comparision_output(int plant_count, int Cumi_Step_units_near, int Cumi_Step_units_far)

{
	cout << endl;
		cout << "*** With " << plant_count << " plants, ";
		
		if (Cumi_Step_units_far>Cumi_Step_units_near)				//Plan comparision output.
			{
				cout<< "Plan Near is better with "<< (Cumi_Step_units_far - Cumi_Step_units_near)<< " fewer step-units.\n"; 
			}
        else if (Cumi_Step_units_far < Cumi_Step_units_near)
			{
				cout<< "Plan Far is better with "<< (Cumi_Step_units_near - Cumi_Step_units_far)<< " fewer step-units.\n";
			}
}