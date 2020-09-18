#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;

void merge_two_lists(node*, node*);
void create_list(int, node*);
void free_list(node* head);

int main()
{
	//Initialising headers for the linked lists
	node *h1 = (node*)malloc(sizeof(node));
	node *h2 = (node*)malloc(sizeof(node));

	//If memory in the heap does not get allocated return error;
	if (h1 == NULL || h2 == NULL)
	{
		printf("No memory available in heap\n");
		return 1;
	}
	//Creating first list
	int size1, size2;
	printf("Enter the number of elements in first linked list\n");
	scanf_s("%d", &size1);
	printf("Enter the elements of first linked list\n");
	create_list(size1, h1);

	//Creating second list
	printf("Enter the number of elements of second linked list\n");
	scanf_s("%d", &size2);
	printf("Enter the elements of second linked list\n");
	create_list(size2, h2);

	//Calling function to merge the two linked lists
	merge_two_lists(h1, h2);

	//Program to print the elements in merged linked list
	printf("Elements of the merged linked list\n");
	node* temp = h1;
	while (temp != NULL)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	return 0;

	//Free the combined linked list
	free_list(h1);
}
//Function to merge two linked lists and header of the merged linked list is h1
void merge_two_lists(node* h1, node* h2)
{
	if (h1 == NULL)
	{
		h1 = h2;
		return;
	}
	else if (h1->next == NULL)
	{
		h1->next = h2;
		return;
	}
	else
	{
		node* s1, * e1, * s2, * e2;
		s1 = h1;
		s2 = h2;
		e1 = s1->next;
		e2 = s2->next;
		do
		{
			s1->next = s2;
			s2->next = e1;
			s1 = e1;
			s2 = e2;
			e1 = e1->next;
			e2 = e2->next;
		} while (e1 != NULL && e2 != NULL);
		
		s1->next = s2;
		if(e2 == NULL)
			s2->next = e1;
	}
	return;
}
//Function to create linked list
void create_list(int len, node* head)
{
	int i = 0;
	node* temp = head;
	//[0,i) elements of array inserted into linked list 
	while (i != len)
	{
		scanf_s("%d", &temp->num);
		temp->next = (node* )malloc(sizeof(node));
		if(i != len - 1)
			temp = temp->next;
		++i;
	}
	temp->next = NULL;

	char c;
	//To ignore any extra elements entered by user
	while ((c = getchar()) != '\n');
}

//Function to free memory occupied by linked list
void free_list(node* head)
{
	node* fwd = head;
	node* bwd = head;
	do
	{
		fwd = fwd->next;
		free(bwd);
		bwd = fwd;
	} while (fwd != NULL);
	free(fwd);
	free(bwd);
}
