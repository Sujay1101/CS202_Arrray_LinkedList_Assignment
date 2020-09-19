//Problem 1 of linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;
node* head;

unsigned int length(node*);
void append(int);

int main()
{
	head = NULL;
	int choice;
	int data;
	printf("Enter\n1.To add to list\n2.To check length of list\n3.To exit");
	while (1)
	{
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the data you want to append\n");
			scanf_s("%d", &data);
			append(data);
			break;
		case 2:
			printf("%d\n", length(head));
			break;
		case 3:
			return 0;
		default:
			printf("Enter appropriate option");
		}
		printf("Press 1 or 2 or 3\n");
	}

}

//Returns the length of linked list
unsigned int length(node* p)
{
	if (p == NULL)
		return 0;
	else
	{
		int len = 1;
		node* temp = p;
		while (temp->next != NULL)
		{
			temp = temp->next;
			++len;
		}
		return len;
	}
}

void append(int data)
{
	if (head == NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->num = data;
		head->next = NULL;
		return;
	}
	node* ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = (node*)malloc(sizeof(node));
	ptr->next->num = data;
	ptr->next->next = NULL;
	return;
}
