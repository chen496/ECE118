#include "library.h"


double sign(double number)
{
	if(number==0)

		return 0;
	else
	{
		double result = (-1)*number;
		return result;
	}
}
int fac (int number) 
{
	int result= 1;
	if(number>=1)
		result= number* fac(number-1);
	return result;
}
// second number
double calc(double x, double y, int op) {
    if (op == '+') {
        return x + y;
    } else if (op == '-') {
        return x - y;
    } else if (op == L'x') {
        return x * y;
    } else if (op == L'÷') {
        return x / y;
    }
}


double run(double row, double column)
{
	double amount=0;
    double last=0;
    int op = '+';
	while(true)
	{
		set_pen_color(color::dark_grey);
		fill_rectangle(2*row,2*row, 70*column, 9*column);
		set_pen_color(color::yellow);
		move_to(3*row, 10*column);
		write_string(amount);
		wait_for_mouse_click();
		int  x = get_click_x();
		int  y = get_click_y();
		if (y>13*row && y<22*row)
		{
			if (x>2*column && x<11*column)
			{
				amount= amount*10+7;
				print(amount);
				
			}
			else if (x>14*column && x<23*column)
			{
				amount= amount*10+8;
				print(amount);
				
			}
			else if (x>26*column && x<35*column)
			{
				amount= amount*10+9;
				print(amount);
				
			}
			else if (x>38*column && x<47*column)
			{
                last = calc(last, amount, op);
				op = '+';
                amount = 0;  // reinitialize
				print(last);
				
			}
			else if (x>50*column && x<59*column)
			{
				if (x<0)
					amount;
				
				else
				{
					amount= fac(amount);
					print(amount);
					
				}
			}
			else if (x>62*column && x<71*column)
			{
				amount= amount/100;
				print(amount);
			}
		}
		else if (y>25*row && y<34*row)
		{
			if (x>2*column && x<11*column)
			{
				amount= amount*10+4;
				print(amount);
				
			}
			else if (x>14*column && x<23*column)
			{
				amount= amount*10+5;
				print(amount);
				
			}
			else if (x>26*column && x<35*column)
			{
				amount= amount*10+6;
				print(amount);
				
			}
			else if (x>38*column && x<47*column)
			{
                last = calc(last, amount, op);
                op = '-';
                amount = 0;
				print(last);
			}
			else if (x>50*column && x<59*column)
			{
				amount= sign(amount);
				print(amount);
				
			}
			else if (x>62*column && x<71*column)
			{
				amount= 1/amount;
				print(amount);
				
			}
		}
		else if (y>37*row && y<46*row)
		{
			if (x>2*column && x<11*column)
			{
				amount= amount*10+1;
				print(amount);
				
			}
			else if (x>14*column && x<23*column)
			{
				amount= amount*10+2;
				print(amount);
				
			}
			else if (x>26*column && x<35*column)
			{
				amount= amount*10+3;
				print(amount);
				
			}
			else if (x>38*column && x<47*column)
			{
                last = calc(last, amount, op);
                op = L'×';
				amount=0;
                print(last);
				
			}
			else if (x>50*column && x<59*column)
			{
				if(amount<0)
					amount; 
				
				else
				{
					amount= sqrt(amount);
					print(amount);
					
				}
			}
			else if (x>62*column && x<71*column)
			{
				amount= 3.141592654;
				print(amount);
				
			}
		}
		else if (y>49*row && y<58*row)
		{
			if (x>2*column && x<11*column)
			{
				amount= 0;
				print(amount);
				
			}
			if (x>14*column && x<23*column)
			{
				amount= amount*10+0;
				print(amount);
			}
			if (x>26*column && x<35*column)
			{
                // op = '='
                last = calc(last, amount, op);
				amount=last;
				print(amount);
				
			}
			if (x>38*column && x<47*column)
			{
				last = calc(last, amount, op);
                op = L'÷';
                amount = 0;
				print(last);
			}
			if (x>50*column && x<59*column)
			{
				amount= amount*amount;
                last = amount;
				print(amount);
			}
			if (x>62*column && x<71*column)
			{
				amount= random_in_range(0,1000);
				print(amount);
				
			}
		}
		new_line();
	}

}

const int symbol[]={'7', '8', '9', '+', '!' ,'4', '5', '6', '-',L'±', '1', '2','3',L'×', L'√','c','0','=',L'÷','x',L'²', '%', 'I', L'π', 'R'};

void thechar(double row[], double column[], double size, int i, int  j)
{
	set_pen_color(color::light_grey);
	set_font_size(size);
	double  x = row[i]+.16*size;
	double  y = column[j]+.8*size;
	move_to(x, y);
	if (j==1 && i==0) write_char(symbol[i]);
	else if (j==1 && i==1) write_char(symbol[i]);
	else if (j==1 && i==2) write_char(symbol[i]);
	else if (j==1 && i==3) write_char(symbol[i]);
	else if (j==1 && i==4) write_char(symbol[i]);
	else if (j==1 && i==5) write_char(symbol[21]);
	else if (j==2 && i==0) write_char(symbol[5]);
	else if (j==2 && i==1) write_char(symbol[6]);
	else if (j==2 && i==2) write_char(symbol[7]);
	else if (j==2 && i==3) write_char(symbol[8]);
	else if (j==2 && i==4) write_char(symbol[9]);
	else if (j==2 && i==5) write_char(symbol[22]);
	else if (j==3 && i==0) write_char(symbol[10]);
	else if (j==3 && i==1) write_char(symbol[11]);
	else if (j==3 && i==2) write_char(symbol[12]);
	else if (j==3 && i==3) write_char(symbol[13]);
	else if (j==3 && i==4) write_char(symbol[14]);
	else if (j==3 && i==5) write_char(symbol[23]);
	else if (j==4 && i==0) write_char(symbol[15]);
	else if (j==4 && i==1) write_char(symbol[16]);
	else if (j==4 && i==2) write_char(symbol[17]);
	else if (j==4 && i==3) write_char(symbol[18]);
	else if (j==4 && i==4) 
	{
		write_char(symbol[19]);
		write_char(symbol[20]);
	}
	else if (j==4 && i==5) write_char(symbol[24]);
}


void button(double row[],double column[], double size)
{
	double const sizeofbutton= 9*size;
	double const display= 57.0*size;

	for(int i=0; i<6; i++)
	{

		for(int j=0; j<5; j++)
		{

			if(j==0)
			{

				if(i==0)
				{
				set_pen_color(color::light_grey);
				fill_rectangle(column[j]-1, row[i]-1, display+2, sizeofbutton+2);
				set_pen_color(color::dark_grey);
				fill_rectangle(column[j], row[i], display, sizeofbutton); 
				}

			}

			else
			{
				set_pen_color(color::light_grey);
				fill_rectangle(column[i]-1, row[j]-1, sizeofbutton+2, sizeofbutton+2);
				set_pen_color(color::dark_grey);
				fill_rectangle(column[i], row[j], sizeofbutton, sizeofbutton);
				thechar(column, row, sizeofbutton,i,j);
			}
		}
	}
}


void main()
{
	int size=500;
	double  x=size+size/16;
	double y= 0.87*size; 
	make_window(x,y);
	set_pen_color(color::grey);
	fill_rectangle(0.0,0.0,x,y);
	double  button_size= size/71;
	double  x= size/70.0; 
	double  y = size/71.0;
	double  row_start_pos[6]={2*x, 13*x, 25*x, 37*x, 49*x, 61*x};
	double  column_start_pos[6]={2*y, 14*y, 26*y, 38*y,50*y, 62*y};
	button(row_start_pos, column_start_pos, button_size);
    run(x, y);
}





