#include <iostream.h>

//class private�� struct public������ ��Ȩ������
class Point
//struct Point
{
//class Ĭ��private
public:
	int x;
	int y;
	void output()
	{
		cout<<x<<endl<<y<<endl;
	}
protected:
	void output2()
	{
		cout<<x<<endl<<y<<endl;
	}

};

class NPoint : public Point
{
public :
	//������ʼ��
	NPoint():Point(),a(1)
	{
		cout<<"point construct "<<endl;

	}
	~NPoint()
	{
		cout<<"point deconstruct"<<endl;
	}
private :
	const int a;

};

void main2()
{
	Point pt;
	//class�ᱨ��
	pt.x = 5;
	pt.y = 6;
	pt.output();
}
