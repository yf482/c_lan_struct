#include <iostream.h>
void change(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void main()
{
	int x=3;
	int y=4;
	int &b=x;
	b=5;
	cout<<"x="<<b<<endl;

	change(x,y);
	cout<<x<<"|"<<y<<endl;



}

