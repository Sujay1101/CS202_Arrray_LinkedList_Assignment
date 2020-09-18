//Problem 13 of linked list
//Two sparse matrices can be multiplied to get a dense matrix 
//so the multiplication has been stored in multidimensional array

#include<stdio.h>
#include<stdlib.h>

typedef struct cell{
	int val;
	int hor;
	int ver;
}cell;

typedef struct node {
	cell c;
	struct node* next;
}node;

int** mmul(node*, node*);
node* create_list(int);
void print_list(node*);

//mxn is dimension of first matrix and nxp is dimension of second matrix
int m, n, p;

int main()
{
	int ra, rb,t;
	printf("Enter the dimensions of first matrix like mxn\n");
	scanf_s("%d%d", &m, &n);
	printf("Enter the number of non-zero elements in first matrix\n");
	scanf_s("%d", &ra);
	node *a = create_list(ra);

	printf("Enter the dimensions of second matrix like mxn\n");
	scanf_s("%d%d",&t,&p);
	if (t != n)
	{
		printf("The matrices cannot be multiplied\n");
		return 0;
	}
	printf("Enter the number of non-zero elements in second matrix\n");
	scanf_s("%d", &rb);
	node* b = create_list(rb);


	int** c = mmul(a, b);
	printf("The multiplication matrix\n");
	for (int i = 0; i != m; ++i)
	{
		for (int j = 0; j != p; ++j)
			printf("%d ", c[i][j]);
		putchar('\n');
	}
	return 0;
}

int** mmul(node* a, node* b)
{
	//Creating the product matrix with all positions initialised to zero
	int** c = (int**)(malloc(sizeof(int*) * m));
	for (int i = 0; i != m; ++i)
	{
		c[i] = (int*)malloc(sizeof(int) * p);
		for (int j = 0; j != p; ++j)
			c[i][j] = 0;
	}

	//Traversing through all possible pairs formed by both the linked lists 
	node* tempa = a, * tempb;
	do
	{
		tempb = b;
		do
		{
			//If the horizontal position of number in a matches with vertical position in b it can be multiplied
			if (tempa->c.hor == tempb->c.ver)
				//Product will be added at position with ver same as number in a and hor same as number in b
				c[tempa->c.ver][tempb->c.hor] += tempa->c.val * tempb->c.val;

			//Incrementing pointer to second list
			tempb = tempb->next;

		} while (tempb != NULL);

		//Incrementing pointer to first list
		tempa = tempa->next;
	} while (tempa != NULL);

	return c;
}

node* create_list(int size)
{
	node* head = (node *)malloc(sizeof(node));
	node* temp = head;
	printf("Enter the number, horizontal position, vertical position\n");
	for (int i = 0; i != size; ++i)
	{
		//Initialising the fields of next node
		scanf_s("%d%d%d", &temp->c.val,&temp->c.hor,&temp->c.ver);
		if (i != size - 1)
		{
			//Allocating space for next node
			temp->next = (node*)malloc(sizeof(node));
			//Advancing temporary pointer to point to the next node in list
			temp = temp->next;
		}
	}
	temp->next = NULL;

	return head;
}

void print_list(node* x)
{
	node *temp = x;
	if (x == NULL)
	{
		printf("Empty list\n");
		return;
	}

	do
	{
		printf("%d %d %d\n", temp->c.val, temp->c.hor, temp->c.ver);
		temp = temp->next;
	} while (temp != NULL);

	return;
}