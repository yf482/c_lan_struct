#include <iostream.h>
//using namespace std;

//�ṹ����������
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
	//����������������
	~Point()
	{
	
	}

	void output()
	{
		cout<<x<<endl<<y<<endl;
	}
//�������صĸ���
	void output(int a,int b)
	{
		x=a;
		y=b;
	}
//this������
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