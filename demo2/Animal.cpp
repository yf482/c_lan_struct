#include "Animal.h"
#include <iostream.h>
//˫���źͼ��������𣬲�������<>ϵͳĿ¼ ""�ǵ�ǰĿ¼�����ٲ���ϵͳĿ¼

Animal::Animal()
{
}
Animal::Animal(int x,int y)
{
	this->x=x;
	this->y=y;
}

void Animal::eat()
{
	cout<<"animal eat"<<endl;
}

void Animal::sleep()
{
	cout<<"animal sleep"<<endl;
}

void Animal::breathe()
{
	cout<<"animal breathe"<<endl;
}