#include <malloc.h>
#include <stdio.h>
#include "util.h"
#include<assert.h>


#define ARYSIZE	5	

typedef  struct node
{
	int           data;
	struct node   *next;
} NODE;


NODE * InsertNode(NODE *p, int n)
{
	NODE *temp;
	temp = (NODE *) malloc(sizeof(NODE));
//	printf("malloc at %u\n", temp);

	if (temp != NULL) 
	{
		temp->data = n;
		temp->next = p;
	}
	return temp;
}


void PrintList(NODE *head)
{
	assert(head!=NULL);
	NODE *temp = head;

	while ( temp != NULL )
	{
		printf("%d --> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

void DeleteList(NODE* head)
{
	NODE *temp = head;

	while(temp != NULL)
	{
		temp = head->next;
	//	printf("freeing %u \n", head);
		free(head);
		head = temp;
	}
}

// ***********************************************
//  SearchList searches for the specific "val" 
//  in the list pointed by "head"
//  returns :
//        address of the node if it is present
//        otherwise returns NULL
//
NODE* SearchList(NODE *head, int val)
{
	NODE *temp = head;

	while (temp != NULL)
	{
		if (temp->data == val)
			break;
		temp = temp->next;
	}

	return temp;
}

void search_for_val(NODE* pHead, int val)
{
	NODE *pNode;

	pNode = SearchList(pHead, val);

	if (pNode != NULL)
	{
		printf("%d found in ll\n", val);
	}
	else
	{
		printf("%d not found in ll\n", val);
	}
}

void test_ll_search(NODE* head, int a[], int arysize)
{
	int min,max;

	search_for_val(head, a[0]);
	if(arysize!=1)
	{
		search_for_val(head, a[1]);

		search_for_val(head, a[(arysize-1)/2]);

		search_for_val(head, a[arysize-2]);
		search_for_val(head, a[arysize-1]);
	}
	get_min_max(a, arysize, &min, &max);
	printf("max=%d\tmin=%d\n",max,min);
	search_for_val(head, min-1);
	search_for_val(head, max+1);

}

void test_ll()
{
	NODE *head = NULL;
	int nary[ARYSIZE];
	int   k;

	fill_array_with_rand(nary, ARYSIZE, 1);


	printf("*** creating list\n");
	for( k=0; k< ARYSIZE; k++ )   {
		head = InsertNode( head, nary[  k ] );
	}

	PrintList(NULL);

	test_ll_search(head, nary, ARYSIZE);

	DeleteList(head);

}

int main()
{
	test_ll();

	return 0;
}





	
