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
	//�麯�� �ٰ� ��̬
	virtual void eat()
	{
		cout<<"animal eat"<<endl;
	}
	//���麯�� ������ ����ʵ����,�ᱨ���̳�ʵ��
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
//������д
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

	//��������ִ������
	//����ת��Ҫ���ڴ�ģ��
	Fish fh2;
	Animal *pAn;
	pAn = &fh2;
	fn(pAn);


}