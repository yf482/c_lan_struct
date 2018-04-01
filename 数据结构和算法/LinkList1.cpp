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
//  在尾部插入节点
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
//  在第p个节点  后插入一个值为X的节点
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
//在第p个节点 前插入一个值为x的节点
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
//  删除位置p的节点
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
//  删除整个链表
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
// 输出链表
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
//  求链表的长度
{
	int i=0;
	while(llist->link!=NULL)
	{
		i=i+1;
		llist=llist->link;
	}
	cout<<"链表长度："<<i<<endl;

}

int Locate_Link(LinkList llist,int x)
//查找链表中是否存在一个值为x的节点，如果有则返回第一次出现的该值的节点
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

