#include "Animal.h"
#include <iostream.h>
//双引号和尖括号区别，查找区别<>系统目录 ""是当前目录查找再查找系统目录

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