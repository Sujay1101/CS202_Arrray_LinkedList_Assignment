#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int num;
	struct node* next;
}node;

typedef struct circ {
	node* front;
	node* rear;
}circ;

int* delete_circ(circ*);
void append_circ(circ*, int);
circ* create_circ();
void print_circ(c);

int main()
{
	int key;
	circ* c = create_circ();
	int op;
	printf("Press \n0 to stop program\n1 to append to list\n2 to delete from list\n");
	do
	{
		scanf_s("%d", &op);
		switch (op) {
		case 0:
			break;
		case 1:
			printf("Enter the value to append\n");
			scanf_s("%d", &key);
			append_circ(c, key);
			print_circ(c);
			break;
		case 2:
		{
			int* p = delete_circ(c);
			printf("You deleted %d\n", *p);
			print_circ(c);
			break;
		}
		default:
			printf("Enter an appropriate number\n");
		}
		if (op)
			printf("Press 0 or 1 or 2 again\n");

	} while (op);

	return 0;
}

circ* create_circ()
{
	circ* c = (circ*)malloc(sizeof(circ));
	c->front = NULL;
	c->rear = NULL;
	return c;
}
int* delete_circ(circ* c)
{
	node* temp = c->front;
	if (temp == NULL)
	{
		printf("Deletion from empty list!");
		return NULL;
	}

	if (c->front != c->rear)
	{
		c->front = c->front->next;
		//Setting next field of last node to point to the first node
		c->rear->next = c->front;
	}
	else
	{
		c->front = NULL;
		c->rear = NULL;
	}

	//Returning the value of num field of the node just deleted 
	return &temp->num;
	free(temp);
}

void append_circ(circ* c, int key)
{
	//Allocating space for the node to be apended
	node* temp = (node*)(malloc(sizeof(node)));
	if (temp == NULL) {
		printf("Appending Unsuccessful. Try again\n");
		return;
	}
	//Initialising the fields of node to be added
	temp->num = key;

	//If the list is empty
	if (c->front == NULL)
		c->front = temp;
	//If the list is not empty
	else
		c->rear->next = temp;
	c->rear = temp;
	temp->next = c->front;
	return;
}

void print_circ(circ* c)
{
	if (c->front == NULL)
		printf("List is empty\n");
	else
	{
		printf("These are teh elements currently in the list\n");
		node* temp = c->front;
		do
		{
			printf("%d ", temp->num);
			temp = temp->next;
		} while (temp != c->front);
	}
	putchar('\n');
	return;
}