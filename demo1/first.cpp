#include <iostream.h>
//using namespace std;

//结构体和类的区别
struct Point
//class Point
{
//private:
//protected:
public:
	int x;
	int y;
	
	Point()
	{
		x=0;
		y=0;
	}
	Point(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	//析构函数，销毁类
	~Point()
	{
	
	}

	void output()
	{
		cout<<x<<endl<<y<<endl;
	}
//函数重载的概念
	void output(int a,int b)
	{
		x=a;
		y=b;
	}
//this的作用
	void output2(int x,int y)
	{
		this->x=x;
		this->y=y;
	}




};

void main2()
{
	Point pt;
	pt.output();
	
	pt.x = 12;
	pt.y = 4;
	pt.output();
	
	
	pt.output(2,2);
	pt.output();

	pt.output2(4,4);
	pt.output();

	Point pt2(3,3);
	pt2.output();
}