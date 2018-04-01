#include<malloc.h>
#include<iostream.h>
#define DataType int  
struct SeqStack{
	int MAXNUM;
	int t;
	DataType *s;
};
typedef struct SeqStack *PSeqStack;

PSeqStack createEmptyStack_seq(int m){
	PSeqStack pastack=(PSeqStack)malloc(sizeof(struct SeqStack));
	if(pastack!=NULL){
		pastack->s=(int *)malloc(sizeof(int)*m);
		if(pastack->s){
			pastack->MAXNUM=m;
			pastack->t=-1;
			return pastack;
		}
		else free(pastack);
	}
	else{
		cout<<"out of space!"<<endl;
		return NULL;
	}
}


void push_seq(PSeqStack pastack,DataType x){    //在栈中压入一个元素 X   U
    if(pastack->t >=(pastack->MAXNUM)-1)
		cout<<"overflow!"<<endl;
	else{
		pastack->t=(pastack->t)+1;
		pastack->s[pastack->t]=x;
	}
}

void pop_seq(PSeqStack pastack){      //删除栈顶元素   O
    if(pastack->t==-1)
		cout<<"underflow!"<<endl;
	else
		pastack->t=(pastack->t)-1;

}



DataType top_seq(PSeqStack pastack){    //打印栈顶元素   F
    if(pastack->t==-1)
		cout<<"it is empty!"<<endl;
	else
		return(pastack->s[pastack->t]);
}

int len_seq(PSeqStack pastack){     //堆栈长度   L
    if(pastack->t==-1)
		return 0;
	else
		return (pastack->t)+1;
}
void prt_seq(PSeqStack pastack){    //打印栈元素   S
    int a= pastack->t;
	if(pastack->t==-1)
		cout<<"it is empty!"<<endl;
	else
		while(pastack->t!=-1){
			cout<<pastack->s[pastack->t]<<endl;
			pastack->t=(pastack->t)-1;
       	}
     pastack->t=a;
}

void aa_seq(PSeqStack pastack){         //清空堆栈  E
    if(pastack->t==-1)
		cout<<"it is empty"<<endl;
		else
			for(int j=0;j<pastack->MAXNUM;j++){
				pastack->t=(pastack->t)-1;
			}
	
}



int main(){
	char ch;
	int m;
	int x;
	int N=100;
    PSeqStack pp ;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>ch;
		switch(ch){
		case'C':
			cin>>m;
		    pp=createEmptyStack_seq(m);
			break;
		case'U':
			cin>>x;
			push_seq(pp,x);     //在栈中压入一个元素 X   U
            break;
		case'O':
            pop_seq(pp);      //删除栈顶元素   O
			break;
		case'F':
			cout<<top_seq(pp);      //打印栈顶元素   F
			break;
		case'L':
			cout<<len_seq(pp);     //堆栈长度   L
			break;
		case'S':
			prt_seq(pp);   //打印栈元素   S
			break;
		case'E':              //清空堆栈  E
			aa_seq(pp);
			break;
		}
	}


return 0;
}