#include <stdio.h>
#include <malloc.h>

#define ELEMTYPE int
#define POSITION int
#define SIZE_T int

struct SQList {
ELEMTYPE * elements;
SIZE_T length;
SIZE_T maxNum;
};
typedef struct SQList * SeqList;

SeqList createNullList_seq(SIZE_T m) //�����ƶ����ȵ�����
{
	SeqList palist=(SeqList)malloc(sizeof(struct SQList));
		if(palist!=NULL){
			palist->elements=(ELEMTYPE *)malloc(sizeof(ELEMTYPE)*m);
			if(palist->elements){
				palist->maxNum=m;
				palist->length=0;
				return palist;
			}
			else free(palist);
		}
		printf("out of space!!\n");
		return NULL;
}

void destroySeqList(SeqList palist) //�������
{
	if(palist!=NULL)
	{
	if(palist->elements!=NULL)
	free(palist->elements);
	free(palist);
	}
}

void printSeqList(SeqList palist){//�������Ԫ��
if(palist==NULL)
		printf("no element\n");
	else
		for(int i=0;i<=palist->length;i++)
	printf("%d",palist->elements[i]);

	printf("\n");

}

SIZE_T lengthSeqList(SeqList palist){//���������
if(palist==NULL)
printf("no element\n");
else
{
int i;
i=palist->length;
printf("%d",i);
}
return 0;
}

int getVertexSeqList(SeqList palist, POSITION p, ELEMTYPE *x)//��ȡָ��λ�õĽڵ�
{
if(p<0 || p>palist->length)
printf("no exit this pasition\n");
else
*x=palist->elements[p];
printf("%d",*x);
return 0;
}

POSITION locateVertexSeqList(SeqList palist, ELEMTYPE x)//����ĳ������
{
for(int i=0;i<palist->length;i++)
if(palist->elements[i]==x)
printf("%d",i);
else
return -1;
}

int insertPreSeqList(SeqList palist, POSITION p, ELEMTYPE x)//��POSITION p ָ�������Ԫ��ǰ����һ���µ�Ԫ��x
{
int q;
if(palist->length>=palist->maxNum){
printf("overflow!\n");
return 0;
}
if(p<0||p>palist->length){
printf("not exist!\n");
}
for(q=palist->length-1;q>=p;q--){
palist->elements[q+1]=palist->elements[q];
palist->elements[p]=x;
palist->length=palist->length+1;
return 1;
}
}

int insertPostSeqList(SeqList palist, POSITION p, ELEMTYPE x){//��POSITION p ָ�������Ԫ�غ����һ���µ�Ԫ��x
    int i;
	if(palist->length>=palist->maxNum){
		printf("Overflow!!!\n");
		return 0;
	}
	else{
		for(i=palist->length;i>p+1;i--){
			palist->elements[i]=palist->elements[i-1];
		}
		palist->elements[i]=x;
		palist->length++;
		return 1;
	}
}

int appendElemSeqList(SeqList palist, ELEMTYPE x)//��β������Ԫ��
{
	if(palist->length>=palist->maxNum){
		printf("Overflow!!!\n");
		return 0;
	}
	else{
palist->elements[palist->length]=x;
palist->length=palist->length+1;
return 0;
	}
}

int deleteElemSeqList(SeqList palist, ELEMTYPE x){//��˳���list �У�ɾ����һ��ֵΪx ����Ԫ�أ�������ڵĻ�
	for(int i=0;i=palist->length;i++)
		if(palist->elements[i]==x)
			for(int q=palist->length-1;q>=i;q--){
	palist->elements[i]=palist->elements[i+1];
    palist->elements[q]=x;
    palist->length=palist->length-1;
			}
			return 0;
}
int deleteVertexSeqList(SeqList palist, POSITION p)//ɾ���ڵ�
{
	int i;
		if(p<0||p>palist->length-1){
		printf("Not exist!\n");
		return 0;
		}
		for(i=p;i<palist->length;i++)
		palist->elements[i]=palist->elements[i+1];
		palist->length-1;
		return 0;

}
int main(){
	int i,j;
    char choose;
	SeqList mypalist;
	while(true){
    scanf("%c",&choose);
	switch(choose){
	
	case'C':
		scanf("%d",&i);
        mypalist=createNullList_seq(i);
        break;
	
	case'W':
        destroySeqList(mypalist);
		break;
	
	case'P':
		printSeqList(mypalist);
		break;

	case'L':
		lengthSeqList(mypalist);
		break;
 
	case'E':
		scanf("%d",&i);
		getVertexSeqList(mypalist,i,&j);
		break;

	case'F':
		scanf("%d",&i);
		locateVertexSeqList(mypalist,i);
		break;

	case'B':
		scanf("%d",&i);
		scanf("%d",&j);
        insertPreSeqList(mypalist,i,j);
		break;

	case'A':
		scanf("%d",&i);
		scanf("%d",&j);
		insertPostSeqList(mypalist,i,j);
		break;
	
	case'R':
		scanf("%d",&i);
        appendElemSeqList(mypalist,i);
		break;

	case'D':
		scanf("%d",&i);
		deleteElemSeqList(mypalist,i);
	    break;

	case'S':
        scanf("%d",&i);
        deleteVertexSeqList(mypalist,i);
		break;

	default:
		break;
	}
	}
return 0;
}

