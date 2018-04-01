#ifndef ANIMAL_H_H
#define ANIMAL_H_H

class Animal 
{

public:
	int x,y;
	Animal();
	Animal(int width,int height);
	
	void eat();

	void sleep();

	virtual void breathe();//=0
};

#endif