#include <iostream.h>
class Animal
{
	
	
public:
	int x,y;
	Animal()
	{
		cout<<"animal construct "<<endl;
	}
	Animal(int a,int b)
	{
		x=a;
		y=b;
		cout<<"animal construct "<<endl;
	}
	
	~Animal()
	{
		cout<<"animal xigou "<<endl;
	}
	void po()
	{
		cout<<x<<"|"<<y<<endl;
	}
	//虚函数 迟绑定 多态
	virtual void eat()
	{
		cout<<"animal eat"<<endl;
	}
	//纯虚函数 抽象函数 不能实例化,会报错，继承实现
	//virtual void run()=0;

	
protected:
	void sleep()
	{
		cout<<"animal sleep"<<endl;
	}
private:
	void study()
	{
		cout<<"animal study"<<endl;
	}
};

class Fish : public Animal
{
public:
	Fish():Animal(400,300)
	{
		cout<<"fish construct"<<endl;
	}
	~Fish()
	{
		cout<<"fish deconstruct"<<endl;
	}
//函数重写
	//void eat()
	virtual void eat()
	{
		Animal::eat();
		cout<<"fish eat"<<endl;
	}
	void test()
	{
		cout<<"test"<<endl;
	}

};

void fn(Animal *pAn)
{
	pAn->eat();
}

void main3()
{
	Animal an;
	an.eat();
	Fish fh;
	fh.po();
	fh.eat();
	fh.test();

	//父类引用执行子类
	//类型转换要看内存模型
	Fish fh2;
	Animal *pAn;
	pAn = &fh2;
	fn(pAn);


}