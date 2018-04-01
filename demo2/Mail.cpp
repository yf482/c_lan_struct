#include <iostream.h>

//class private和 struct public的区别 ，权限区别
class Point
//struct Point
{
//class 默认private
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
	//常量初始化
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
	//class会报错
	pt.x = 5;
	pt.y = 6;
	pt.output();
}
