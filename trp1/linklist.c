#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *insert(NODE *p,int i)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp!=NULL)
	{
		temp->data=i;
		temp->next=p;
	}
return temp;
}
void print(NODE *p)
{
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
int main()
{
	NODE *head=NULL;
	head=insert(head,5);
	head=insert(head,8);
	head=insert(head,3);
	print(head);
}

