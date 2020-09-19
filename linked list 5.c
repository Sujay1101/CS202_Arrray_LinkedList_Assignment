//Problem 5 in linked list

#include<stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct cir {
	node* front;
	node* rear;
}cir;

cir c;

void initialise_list();
int append_list(int);
int delete_list(int);
void print_list();
node* find_address(int);

int main()
{
	initialise_list();
	int choice;
	int data;
	printf("Press 1 or 2 or 3\n1. To append to list\n2.To delete from list\n3.To exit program\n");
	while (1)
	{
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the data you want to enter\n");
			scanf_s("%d", &data);
			if (append_list(data))
				printf("Appending succesful\n");
			else
				printf("Appending unsuccessful. Please try again");
			print_list();
			break;
		case 2:
			printf("Enter the data you want to delete\n");
			scanf_s("%d", &data);
			if (delete_list(data))
			{
				printf("Deletion successful\n");
				print_list();
			}
			else
			{
				if (c.front != NULL)
					printf("Element was not found\n");
				else
					print_list();
			}
			break;
		case 3:
			return 0;
		default:
			printf("Enter appropriate choice\n");
		}
		printf("Press 1 or 2 or 3\n");
	}
}
//Deletes node with data field = data. Address of node to be deleted is given by find_address function
int delete_list(int data)
{
	node* address = find_address(data);
	//If the list is empty or data is not in list address = NULL
	if (address == NULL)
		return 0;
	//If the list contains only one node front and rear set to NULL
	if (c.front == c.rear)
	{
		c.front = c.rear = NULL;
		free(address);
	}
	else
	{
		//If the node previous to first node is to be deleted then front has to point to the node to be deleted
		if (address->next == c.front)
			c.front = address;
		//If the node previous to last node is to be deleted then rear has to point to the node to be deleted
		if (address->next == c.rear)
			c.rear = address;
		node* temp = address->next;
		//Copying the data of next node to node pointed by address
		address->data = temp->data;
		address->next = temp->next;
		free(temp);
	}
	return 1;
}
//Returns the address of the node with data field as data 
node* find_address(int data)
{
	if (c.front == NULL)
		return NULL;
	if (c.rear->data == data)
		return c.rear;
	node* ptr = c.front;
	while (ptr->data != data && ptr != c.rear)
		ptr = ptr->next;
	if (ptr->data == data)
		return ptr;
	else
		return NULL;
}

void initialise_list()
{
	c.front = NULL;
	c.rear = NULL;
}

int append_list(int data)
{
	node* new = (node*)malloc(sizeof(node));
	if (new == NULL)
		return 0;
	new->data = data;
	if (c.front == NULL)
		c.front = new;
	else
		c.rear->next = new;
	c.rear = new;
	new->next = c.front;

	return 1;
}

void print_list()
{
	if (c.front == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("These are the elements in the list\n");
	node* ptr = c.front;
	do
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	} while (ptr != c.front);
	putchar('\n');
	return;
}