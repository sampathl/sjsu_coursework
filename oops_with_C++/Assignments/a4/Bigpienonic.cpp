
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 100000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

void print(const mpf_t& pi);
void cube_root(mpf_t& x, const mpf_t a);

int main()
{
	mpf_set_default_prec(BIT_COUNT*PRECISION);    // precision in bits
	mpf_t a_1,a_n,a_n_1,a_n_2,a_n_3,a_n_4,a_n_5;   // initializing all the used variables.
	mpf_t r_1,r_2,r_n,r_n_1,r_n_2;
	mpf_t s_1,s_2,s_n,s_n_1,s_n_2,s_n_3,s_n_4,s_n_5;
	mpf_t t_1,t_n;
	mpf_t u_1,u_2,u_3,u_4,u_5,u_n;
	mpf_t v_1,v_2,v_3,v_4,v_n;
	mpf_t w_1,w_2,w_3,w_4,w_n;
	mpf_t pi;
		
	mpf_init (a_1);
	mpf_init (a_n);
	mpf_init (r_1);
	mpf_init (r_2);
	mpf_init (r_n);
	mpf_init (s_1);
	mpf_init (s_2);
	mpf_init (s_n_2);
	mpf_init (t_1);
	mpf_init (t_n);
	mpf_init (u_1);
	mpf_init (u_2);
	mpf_init (u_3);
	mpf_init (u_4);
	mpf_init (u_5);
	mpf_init (u_n);
	mpf_init (v_1);
	mpf_init (v_2);
	mpf_init (v_3);
	mpf_init (v_4);
	mpf_init (v_n);
	mpf_init (w_1);
	mpf_init (w_2);
	mpf_init (w_3);
	mpf_init (w_4);
	mpf_init (w_n);
	mpf_init (a_n_1);
	mpf_init (a_n_2);
	mpf_init (a_n_3);
	mpf_init (a_n_4);
	mpf_init (a_n_5);
	mpf_init (s_n_1);
	mpf_init (s_n_2);
	mpf_init (s_n_3);
	mpf_init (s_n_4);
	mpf_init (s_n_5);
	mpf_init (r_n_1);
	mpf_init (r_n_2);
	mpf_init (pi);


	mpf_set_ui (a_1,1);	
	mpf_div_ui (a_n,a_1,3);		//void mpf_div_ui (mpf_t rop, mpf_t op1 , mpir_ui op2 )
	
	mpf_sqrt_ui (r_1,3);			//void mpf_sqrt_ui (mpf_t rop, mpir_ui op)
	mpf_sub_ui (r_2,r_1,1);		//void mpf_sub_ui (mpf_t rop, mpf_t op1, mpir_ui op2 )
	mpf_div_ui (r_n,r_2,2);		//void mpf_div_ui (mpf_t rop, mpf_t op1 , mpir_ui op2 )
	
	//mpf_set_ui (s_1,1);
	mpf_pow_ui (s_1,r_n,3);		//void mpf_pow_ui (mpf_t rop , mpf_t op1 , mpir_ui op2 )
	mpf_ui_sub (s_2,1,s_1);			//void mpf_div (mpf_t rop , mpf_t op1 , mpf_t op2 )
	cube_root (s_n,s_2);		//void mpf_pow_ui (mpf_t rop , mpf_t op1 , mpir_ui op2 )
	
	int po;

	//Iterating the given formulae for '6' times.
    for (int i = 0; i < MAX_ITERATIONS; i++)
	   {
	   	mpf_mul_ui (t_1,r_n,2);		//void mpf_mul_ui (mpf_t rop, mpf_t op1, mpir_ui op2 ) 
		mpf_ui_add (t_n,1,t_1);
		
		mpf_pow_ui (u_1,r_n,2);
		mpf_add (u_2, r_n,u_1);
		mpf_add_ui (u_3,u_2,1);
		mpf_mul (u_4,u_3,r_n);
		mpf_mul_ui (u_5,u_4,9);
		cube_root (u_n,u_5);
		
		mpf_pow_ui (v_1,t_n,2);
		mpf_mul (v_2,t_n,u_n);
		mpf_pow_ui (v_3,u_n,2);
		mpf_add (v_4,v_1,v_2);
		mpf_add (v_n,v_4,v_3);
		
		
		mpf_pow_ui (w_1,s_n,2);
		mpf_add (w_2,s_n,w_1);
		mpf_add_ui (w_3,w_2,1);
		mpf_mul_ui(w_4,w_3,27);
		mpf_div (w_n,w_4,v_n);	
		
		mpf_ui_sub (a_n_1,1,w_n);
		mpf_set_ui (a_n_2,3);
		po=(2*i)-1;		//unsigned long  int mpz_get_ui (mpz_t) refere pafe 23.
		mpf_pow_ui (a_n_3,a_n_2,po);
		mpf_mul (a_n_4,a_n_3,a_n_1);
		mpf_mul (a_n_5,w_n,a_n);
		mpf_add (a_n,a_n_5,a_n_4);
		
		mpf_ui_sub (s_n_1,1,r_n);
		mpf_pow_ui (s_n_2,s_n_1,3);
		mpf_mul_ui (s_n_3,u_n,2);
		mpf_add (s_n_4,t_n,s_n_3);
		mpf_mul (s_n_5,s_n_4,v_n);
		mpf_div (s_n,s_n_2,s_n_5);
		
		mpf_pow_ui (r_n_1,s_n,3);
		mpf_ui_sub (r_n_2,1,r_n_1);
		cube_root (r_n,r_n_2);
		
		mpf_ui_div (pi,1,a_n);
		
	   }
    print(pi);
    return 0;
}

/*Converting the obtained 'pi' value as string and assigning it to a pointer.
 * then printing the output values with required dimensions.
*/
void print(const mpf_t& pi)
{
	char *ptr;
	mp_exp_t expptr;;
	ptr = mpf_get_str (NULL, &expptr, BASE, 0, pi);
	cout << "3.";
	for(int i=1; i < PRECISION; i++)
	{
		if(i%(GROUP_SIZE*LINE_SIZE) > 0)
		{
			if(i%LINE_SIZE > 0)
			{
				if(i%BLOCK_SIZE != 0)
				{
					cout << ptr[i];
				}
				else
			    {
					cout << " ";
			    }
			}
			else
			{
				if(i%BLOCK_SIZE > 0)
				{
					cout << ptr[i];
				}
				else
			    {
					cout << ptr[i];
					cout << "\n  ";
				}
				
			}
		}
		else
		{
			if(i%LINE_SIZE > 0)
			{
				if(i%BLOCK_SIZE != 0)
				{
					cout << ptr[i];
				}
				else
			    {
					
					cout << " ";
			    }
			}
			else
			{
				if(i%BLOCK_SIZE > 0)
				{
					cout << ptr[i];
				}
				else
			    {
					cout << ptr[i];
					cout << "\n  ";
				}
				
			}
			
		}
	}

}

void cube_root(mpf_t& x, const mpf_t a)
{
	mpf_t st,stn,std,a_n,num,den,z;
	mpf_init (st);
	mpf_init (stn);
	mpf_init (std);
	mpf_init (a_n);
	mpf_init (num);
	mpf_init (den);
	mpf_init (z);

	
	
	mpf_set_ui (st,3);

	for (int i=1;i<4;i++)
	{
		mpf_pow_ui (stn,st,3);			
		mpf_mul_ui (std,stn,2);
		mpf_mul (a_n,a,a);
		mpf_add (num,stn,a_n);
		mpf_add (den,std,a);
		mpf_div (z,num,den);
		mpf_mul (x,st,z);
			if (i<4)
			{
				mpf_set (st,x);
			}
	}
	
}

