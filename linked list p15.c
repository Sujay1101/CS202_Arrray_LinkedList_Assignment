//Problem 15 in linked list
//Find out transpose of sparse matrix

#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
	int val;
	int x;
	int y;
}cell;

typedef struct node {
	cell c;
	struct node* next;
}node;

node* mptr(node*);
node* create_linked_list(node*);
void print_linked_list(node*);
void print_matrix(node*, int, int);

//Dimensions of the input matrix
int m, n;

int main()
{
	node* head = malloc(sizeof(node));
	printf("Enter the size of the matrix\n");
	scanf_s("%d%d", &m, &n);

	head = create_linked_list(head);
	printf("The matrix you entered\n");
	print_matrix(head, m, n);
	node* b = mptr(head);
	printf("The transpose\n");
	print_matrix(b, n, m);
}
node* mptr(node* a)
{
	node* temp1 = a;
	node* head = (node*)malloc(sizeof(node));
	node* temp2 = head;
	do
	{
		//Initialising the new node in the transpose linked list 
		temp2->c.x = temp1->c.y;
		temp2->c.y = temp1->c.x;
		temp2->c.val = temp1->c.val;

		//Advancing the pointer to next node in original linked list
		temp1 = temp1->next;

		//Allocating space for new node in transpose linked list
		temp2->next = (node*)malloc(sizeof(node));
		if (temp2->next == NULL)
			return NULL;

		//Advancing pointer to newly allocated memory
		if (temp1 != NULL)
			temp2 = temp2->next;

	} while (temp1 != NULL);//If temp1 is NULL all the original list has been traversed
	temp2->next = NULL;
	return head;
}

node* create_linked_list(node* x)
{
	int n;
	node* temp = x;

	printf("Enter the number of non-zero elements in matrix\n");
	scanf_s("%d", &n);
	printf("Enter the value, horizontal position, vertical position\n");
	for (int i = 0; i != n; ++i)
	{
		scanf_s("%d%d%d", &temp->c.val, &temp->c.x, &temp->c.y);
		temp->next = (node*)malloc(sizeof(node));
		if (i != n - 1)
			temp = temp->next;
	}
	temp->next = NULL;
	return x;
}

void print_linked_list(node* x)
{
	node* temp = x;
	if (x == NULL)
	{
		printf("List is empty\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d %d %d\n", temp->c.val, temp->c.x, temp->c.y);
		temp = temp->next;
	}
	return;
}

void print_matrix(node* x, int h, int w)
{
	//Creating and initialising 2-D array with all elements zero
	int** mat = (int*)malloc(sizeof(node));
	if (mat == NULL)
		return;
	for (int i = 0; i != h; ++i)
	{
		mat[i] = (int*)malloc(sizeof(int) * w);

		if (mat[i] == NULL)
			return;

		for (int j = 0; j != w; ++j)
			mat[i][j] = 0;
	}

	//Incrementing the matrix at positions indicated by linked list
	node* temp = x;
	do
	{
		mat[temp->c.y][temp->c.x] += temp->c.val;
		temp = temp->next;
	} while (temp != NULL);

	for (int i = 0; i != h; ++i)
	{
		for (int j = 0; j != w; ++j)
		{
			printf("%d ", mat[i][j]);
		}
		putchar('\n');
	}

	return;
}
