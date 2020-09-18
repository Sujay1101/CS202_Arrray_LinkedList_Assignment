#include <stdio.h>

typedef struct node {
	int num;
	struct node* next;
}node;

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