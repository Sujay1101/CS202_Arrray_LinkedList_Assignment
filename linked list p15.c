#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int x;
	int y;
	int val;
	struct node* next;
}node;

node* mptr(node* a, node* b)
{
	node *temp1 = a;
	node *temp2 = b;

	do
	{
		//Initialising the new node in the transpose linked list 
		temp2->x = temp1->y;
		temp2->y = temp1->x;
		temp2->val = temp1->val;

		//Advancing the pointer to next node in original linked list
		temp1 = temp1->next;

		//Allocating space for new node in transpose linked list
		temp2->next = (node*)malloc(sizeof(node));
		if (temp2->next == NULL)
			return NULL;

		//Advancing pointer to newly allocated memory
		if(temp1 != NULL)
			temp2 = temp2->next;

	} while (temp1 != NULL);//If temp1 is NULL all the original list has been traversed
	temp2->next = NULL;
	return b;
}

node* create_linked_list(node* x)
{
	printf("Enter the number of non-zero elements in matrix\n");
	int n;
	node* temp = x;
	scanf_s("%d", &n);
	printf("Enter the value, horizontal position, vertical position\n");
	for (int i = 0; i != n; ++i)
	{
		scanf_s("%d%d%d", &temp->val, &temp->x, &temp->y);
		temp->next = (node*)malloc(sizeof(node));
		if(i != n - 1)
			temp = temp->next;
	}
	temp->next = NULL;
	return x;
}

void print_linked_list(node* x)
{
	node* temp = x;
	while (temp != NULL)
	{
		printf("%d %d %d\n", temp->val, temp->x, temp->y);
		temp = temp->next;
	}
	return;
}
int main()
{
	node* head = malloc(sizeof(node));
	head = create_linked_list(head);
	node* b = (node *)malloc(sizeof(node));
	b = mptr(head,b);
	print_linked_list(b);
}