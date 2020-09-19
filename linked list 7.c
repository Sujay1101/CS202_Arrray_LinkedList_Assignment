//Problem 7 of linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;

typedef struct deque
{
	node* front;
	node* rear;
}deque;

void append(deque*, node**, int);
void prepend(deque*, node**, int);
void print_linked_list(node*);

int main()
{
	deque* q = (deque*)malloc(sizeof(deque));
	q->front = NULL;
	q->rear = NULL;
	node* temp;
	int choice;
	int data;
	printf("Enter\n1.to append\n2.To prepend3.to exit\n");
	while (1)
	{
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the value tou want to append\n");
			scanf_s("%d", &data);
			append(q, &temp, data);
			print_linked_list(q->front);
			putchar('\n');
			break;
		case 2:
			printf("Enter the value you want to append\n");
			scanf_s("%d", &data);
			prepend(q, &temp, data);
			print_linked_list(q->front);
			putchar('\n');
			break;
		case 3:
			return 0;
		default:
			printf("Enter appropriate option\n");

		}
		printf("Enter 1 or 2 or 3\n");
	}
}
void append(deque* q, node** temp, int key)
{
	//Allocating space for the node to be inserted
	*temp = (node*)malloc(sizeof(node));
	if (*temp == NULL)
		return;

	//Initialising the fields of the node
	(*temp)->num = key;
	(*temp)->next = NULL;

	//If the list is empty front points to new node else last node of list points to new node
	if (q->rear != NULL)
		q->rear->next = *temp;
	else
		q->front = *temp;
	q->rear = *temp;
}

void prepend(deque* q, node** temp, int key)
{
	//Allocating space for new node
	*temp = (node*)malloc(sizeof(node));
	if (*temp == NULL)
		return;
	//Initialising the fields of new node 
	(*temp)->num = key;
	(*temp)->next = q->front;

	//Changing front and rear according to the size of list
	if (q->front == NULL)
		q->rear = *temp;
	q->front = *temp;

	return;
}

void print_linked_list(node* head)
{
	printf("The elements currently in list\n");
	node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	return;
}
