#include <iostream.h>

#include "Animal.h"
//�ظ�����
#include "Fish.h"

void fn(Animal *pAn)
{
	pAn->breathe();
}

void main()
{
	Fish fh;
	Animal *pAn;
	pAn=&fh;
	fn(pAn);
}