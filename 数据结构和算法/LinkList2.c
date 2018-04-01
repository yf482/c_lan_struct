#include <stdio.h>
#include <malloc.h>
# include<stdlib.h>
#define DataType int

struct Node;
typedef struct Node * PNode;
struct Node {
	DataType info;
	PNode link;
};
struct List {
	PNode head;
	PNode rear;
	int length;
};
typedef struct List* LinkList;
/*
创建空链表
*/
LinkList createNullListLink(void) {
	LinkList llist = (LinkList)malloc(sizeof(struct List));
	PNode head;
	if (llist == NULL)
	{
		printf("create linkLink fail! \n");
		return NULL;
	}
	head = (PNode)malloc(sizeof(struct Node));
	if (head == NULL) {
		printf("create linkLink fail! \n");
		return NULL;
	}

	llist->head = head;
	llist->rear = head;
	llist->head->link = head;
	llist->length = 0;
	return llist;
}
//判断是否是空链表
int isNullListLink(LinkList llist) {
	if (llist->head->link == llist->rear->link) {
		return 1;
	}
	else {
		return 0;
	}
	//return (llist->length == 0);
}
//输出所有元素
void printLnList(LinkList llist)
{
	PNode p;
	if (llist->length == 0) {
		printf("linkList is null!");
	}
	p = llist->head->link;
	for (int i = 0; i < llist->length; i++)
	{
		printf("%d", p->info);
		p = p->link;
	}

}

//P所指节点后面插入元素X
int insertPostLnList(LinkList llist, int y, DataType x)
{
	PNode q;
	PNode p;
	p = llist->head;
	int i = 0;
	while (i != y + 1)
	{
		p = p->link;
		i++;
	}
	if (llist == NULL || p == NULL)
	{
		printf("not find position!");
		return -1;
	}

	q = (PNode)malloc(sizeof(struct Node));
	if (q != NULL)
	{
		q->info = x;
		q->link = p->link;
		p->link = q;
		llist->length++;
		return 1;
	}
	return 0;
}
//P所指节点前面插入元素X
int insertPreLnList(LinkList llist, int y, DataType x)
{
	PNode q;
	PNode p;
	p = llist->head;

	for (int i = 0; i < y; i++)
	{
		p = p->link;
	}
	if (llist == NULL || p == NULL)
	{
		return -1;
	}

	q = (PNode)malloc(sizeof(struct Node));
	if (q != NULL)
	{
		q->info = x;
		q->link = p->link;
		p->link = q;
		llist->length++;

		return 1;
	}
	return 0;
}
//查找X是否存在
PNode locateVertexLnList(LinkList llist, DataType x) {
	PNode p;
	if (llist == NULL)
	{
		return NULL;
	}
	p = llist->head;
	int i = 0;
	while (p != NULL && p->info != x)
	{
		p = p->link;
		i++;
	}
	if (i >= llist->length)
	{
		printf("表中无这个元素！\n");
		return NULL;
	}
	else {
		printf("查找元素的下标是：\n %d ",i);
		return p;
	}
}


//删除第一个值为X的节点
int deleteELemLnList(LinkList llist, DataType x) 
{

	PNode p, q;
	p = llist->head->link;
	int i = 0;
	if (i < llist->length) {
		while (p != llist->head && p->link->info != x)
		{
			p = p->link;
			i++;
		}
	}
	if (i != llist->length)
	{
		q = p->link;
		p->link = q->link;
		free(q);
		llist->length--;
		return 1;
	}
	else
	{
		printf("删除的元素不存在！\n");
		return 0;
	}
}
//删除节点
int deleteVertexLnList(LinkList llist, int k)
{
	PNode p, q;
	if (llist == NULL)
	{
		return 0;
	}
	if (k > llist->length)
	{
		printf("下标超过表的长度了！\n");
		return 0;
	}
	else {
		p = llist->head;
		int i;
		for (i = 0; i < k; i++)
		{
			p = p->link;
		}
		q = p->link;
		p->link = q->link;
		free(q);
		llist->length--;
		return 1;

	}
}
//删除链表
void destroyLnList(LinkList *llist)
{
	if (llist != NULL) {
		free(llist);
	}
}


//在链表尾部添加元素
int appendElemLnList(LinkList llist, DataType x) {
	PNode p, q;
	if (llist == NULL )
	{
		return -1;
	}
	q = (PNode)malloc(sizeof(struct Node));

	
	p = llist->rear;

	if (q != NULL)
	{
		q->info = x;
		q->link = NULL;
		p->link = q;
		llist->rear = q;
		llist->length++;

		return 1;
	}
	else {
		printf("appentd fail!");
		return 0;
	}
	
}
//后去链表长度
int lengthLnList(LinkList llist) {
	return llist->length;
}

int main() {
	int i;
	int j;
	char choose;
	LinkList myllist;
	int flag = 1;
	myllist = createNullListLink();
	while (flag) {
		printf("please input option code: \n");
		choose = 0;
		scanf("%c", &choose);
		switch (choose) {
		case'W':
			destroyLnList(&myllist);
			break;

		case'P':
			printLnList(myllist);
			break;

		case'L':
			lengthLnList(myllist);
			break;

		case'F':
			scanf("%d", &i);
			locateVertexLnList(myllist, i);
			break;

		case'B':
			scanf("%d", &i);
			scanf("%d", &j);
			insertPreLnList(myllist, i, j);
			break;

		case'A':
			scanf("%d", &i);
			scanf("%d", &j);
			insertPostLnList(myllist, i, j);
			break;

		case'R':
			scanf("%d", &i);
			appendElemLnList(myllist, i);
			break;

		case'D':
			scanf("%d", &i);
			deleteELemLnList(myllist, i);
			break;

		case'S':
			scanf("%d", &i);
			deleteVertexLnList(myllist, i);
			break;

		default:
			break;
		}
	}
	printf("按任意键继续……");
	getchar();
	return 0;
}
