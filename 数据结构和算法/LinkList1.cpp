#include<malloc.h>
#include<iostream.h>
typedef struct Node *PNode;
typedef struct Node *LinkList;
struct Node
{
	int datetype;
	PNode link;

};
LinkList CreatNull_List()
{
	LinkList llist=(LinkList)malloc(sizeof(struct Node));
	if(llist!=NULL)
	{
		llist->link=NULL;
		return llist;
	}
	else 
	{
		cout<<"out of space"<<endl;
		return NULL;
	}

}



int inserLast_List(LinkList llist,int x)
//  ��β������ڵ�
{
     PNode p=(PNode)malloc(sizeof(struct Node));
	 p->datetype=x;
	
    while(llist->link!=NULL)
	 {
         llist=llist->link;
	 }
	 PNode q=llist;
	 q->link=p;
	 p->link=NULL;
	 return 0;
}
int inserPost_List(LinkList llist,int x,int p)  
//  �ڵ�p���ڵ�  �����һ��ֵΪX�Ľڵ�
{
      PNode q=(PNode)malloc(sizeof(struct Node));
	  q->datetype=x;
	   
	  for(int i=1;i<p;i++)
	  {
		  llist=llist->link;
	  }
	  q->link=llist->link->link;
	  llist->link->link=q;

	  return 0;
}

int inserPre_List(LinkList llist,int x,int p)
//�ڵ�p���ڵ� ǰ����һ��ֵΪx�Ľڵ�
{
	PNode q=(PNode)malloc(sizeof(struct Node));
	q->datetype=x;
	for(int i=1;i<p;i++)
	{
		llist=llist->link;
	}
	 q->link=llist->link;
	  llist->link=q;

	return 0;
}

int delete_Link(LinkList llist,int p)
//  ɾ��λ��p�Ľڵ�
{
     for(int i=1;i<p;i++)
	 {
		 llist=llist->link;
	 }
	 PNode q=llist->link;
	 llist->link=q->link;
	 free(q);
	 return 0;

}

int Destroy_Link(LinkList llist)
//  ɾ����������
{
		while(llist->link!=NULL)
		{
			PNode p=llist;
			llist=llist->link;
			free(p);
		}
	

		return 0;
}

void print_Link(LinkList llist)
// �������
{
	while(llist->link!=NULL)
	{
		cout<<llist->link->datetype;
		cout<<" ";
		llist=llist->link;
	}
	cout<<endl;
}

void Length_Link(LinkList llist)
//  ������ĳ���
{
	int i=0;
	while(llist->link!=NULL)
	{
		i=i+1;
		llist=llist->link;
	}
	cout<<"�����ȣ�"<<i<<endl;

}

int Locate_Link(LinkList llist,int x)
//�����������Ƿ����һ��ֵΪx�Ľڵ㣬������򷵻ص�һ�γ��ֵĸ�ֵ�Ľڵ�
{
	int i=0;
	while(llist->link!=NULL && llist->datetype!=x )
	{
		llist=llist->link;
		i++;
	}
	if(llist->datetype!=x)
	{
		cout<<"Not exit"<<endl;
		return -1;
	}
	else
	{
	   cout<<i<<endl;
	   return 0;
	}


}



int main()
{
	LinkList llist;
	char str;
	int x,p;
	int N=100;
	cin>>N;
	
	for(int i=1;i<N;i++)
	{
		cin>>str;
	switch(str)
	{
	case'C':
		llist=CreatNull_List();
		break;
	case'R':
		cin>>x;
        inserLast_List(llist,x);
		break;
	case'P':
		print_Link(llist);
		break;
	case'A':
		cin>>x;
		cin>>p;
		inserPost_List(llist,x,p);
		break;
	case'D':
		cin>>p;
		delete_Link(llist,p);
		break;
	case'B':
		cin>>x;
		cin>>p;
		inserPre_List(llist,x,p);
		break;

	}
	}

	return 0;
}

