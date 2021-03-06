// DataStruct.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
#define DataType int

struct SeqStack
{
	int MAXNUM;
	int top;
	DataType * data;

};
typedef struct SeqStack * PSeqStack;

PSeqStack createEmptyStack(int m)
{
	PSeqStack pstack = (PSeqStack)malloc(sizeof(struct SeqStack));
	if (pstack != NULL) {
		pstack->data = (DataType*)malloc(sizeof(DataType)*m);
		if (pstack->data != NULL) {
			pstack->MAXNUM = m;
			pstack->top = -1;
			return pstack;
		}
		else {
			cout << "out of space2!" << endl;
		}
	}
	else {
		cout << "out of space1!" << endl;
		return NULL;
	}
}


void pushSeq(PSeqStack pstack, DataType val) {
	if (pstack->top >= pstack->MAXNUM - 1) {
		cout << "stack is underflow! can not push val: " << val <<endl;
	}
	else {
		pstack->top++;
		pstack->data[pstack->top] = val;
	}

}

void popSeq(PSeqStack pstack) {
	if (pstack->top == -1) {
		cout << "stack is empty!" << endl;
	}
	else {
		pstack->top--;
	}

}

DataType getStackTop(PSeqStack pstack) {
	if (pstack->top == -1) {
		cout << "stack is empty!" << endl;
		return NULL;
	}
	else {
		return pstack->data[pstack->top];
	}
}

DataType getStackLength(PSeqStack pstack) {
	if (pstack->top == -1) {
		cout << "stack is empty!" << endl;
		return 0;
	}
	else {
		return pstack->top+1;
	}
}

void printStackData(PSeqStack pstack) {
	int t = pstack->top;
	if (pstack->top == -1) {
		cout << "stack is empty!" << endl;
	}
	else {
		while (t != -1) {
			cout << t << " = " << pstack->data[t]<<",\t";
			t--;
		}
		cout << endl;
		
	}
	
}

void clearStack(PSeqStack pstack) {
	if (pstack->top == -1) {
		cout << "stack is empty!" << endl;

	}
	else {
	
		pstack->top = -1;
		cout << "stack is successful!" << endl;
		
	}

}

int main()
{
	PSeqStack pstack = createEmptyStack(10);
	cout << "pstack size : "<<sizeof(pstack) << endl;
	popSeq(pstack);
	pushSeq(pstack,10);
	cout << "pstack size : " <<getStackLength(pstack)<< endl;
	printStackData(pstack);
	cout << "pstack val:" <<getStackTop(pstack) <<endl;
	popSeq(pstack);
	cout << "pstack val:" << getStackTop(pstack) << endl;
	pushSeq(pstack, 11);
	pushSeq(pstack, 12);
	pushSeq(pstack, 13);
	pushSeq(pstack, 14);
	pushSeq(pstack, 15);
	pushSeq(pstack, 16);
	pushSeq(pstack, 17);
	pushSeq(pstack, 18);
	pushSeq(pstack, 19);
	pushSeq(pstack, 20);
	pushSeq(pstack, 21);
	printStackData(pstack);
	clearStack(pstack);
	printStackData(pstack);
	pushSeq(pstack, 21);
	printStackData(pstack);

	cout << "test cpp\n";
	cout << "\n 按任意键继续……";
	cin.clear();
	cin.sync();
	cin.get();
    return 0;
}

