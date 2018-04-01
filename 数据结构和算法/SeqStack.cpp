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


void push_seq(PSeqStack pastack,DataType x){    //��ջ��ѹ��һ��Ԫ�� X   U
    if(pastack->t >=(pastack->MAXNUM)-1)
		cout<<"overflow!"<<endl;
	else{
		pastack->t=(pastack->t)+1;
		pastack->s[pastack->t]=x;
	}
}

void pop_seq(PSeqStack pastack){      //ɾ��ջ��Ԫ��   O
    if(pastack->t==-1)
		cout<<"underflow!"<<endl;
	else
		pastack->t=(pastack->t)-1;

}



DataType top_seq(PSeqStack pastack){    //��ӡջ��Ԫ��   F
    if(pastack->t==-1)
		cout<<"it is empty!"<<endl;
	else
		return(pastack->s[pastack->t]);
}

int len_seq(PSeqStack pastack){     //��ջ����   L
    if(pastack->t==-1)
		return 0;
	else
		return (pastack->t)+1;
}
void prt_seq(PSeqStack pastack){    //��ӡջԪ��   S
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

void aa_seq(PSeqStack pastack){         //��ն�ջ  E
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
			push_seq(pp,x);     //��ջ��ѹ��һ��Ԫ�� X   U
            break;
		case'O':
            pop_seq(pp);      //ɾ��ջ��Ԫ��   O
			break;
		case'F':
			cout<<top_seq(pp);      //��ӡջ��Ԫ��   F
			break;
		case'L':
			cout<<len_seq(pp);     //��ջ����   L
			break;
		case'S':
			prt_seq(pp);   //��ӡջԪ��   S
			break;
		case'E':              //��ն�ջ  E
			aa_seq(pp);
			break;
		}
	}


return 0;
}