#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void create_new_node(int,int,int);
void Printtriples();

// Node to represent Aij in a Linked List for Sparse Matrix
struct Node 
{ 
	int value; 
	int row_position; 
	int column_postion; 
	struct Node *next; 
} *start,*ptr,*r; 


int main() 
{ 
	int rows,columns,v;
	printf("\nEnter the number of rows");
	scanf("%d",&rows);
	printf("\nEnter the number of cloumns");
	scanf("%d",&columns);

	/* Start with the empty list */
	start = NULL; 

	for (int i = 0; i < rows; i++){ 
		for (int j = 0; j < columns; j++) {
			printf("\nEnter the value of the element at (%d,%d)",i+1,j+1);
			scanf("%d",&v);
			// Pass only those values which are non - zero 
			if (v) 
				create_new_node(i+1,j+1,v); 
		}//End of Inner Loop
	}//End of Outer Loop
	Printtriples(); 

	return 0; 
} //End of Main

void create_new_node(int row, int column, int v) 
{ 
	
	ptr = start; 
	if (ptr == NULL) 
	{ 
		// Create new node dynamically 
		ptr = (struct Node *) malloc (sizeof(struct Node)); 
		ptr->value = v; 
		ptr->row_position = row; 
		ptr->column_postion = column;
		ptr->next = NULL; 
		start = ptr; 

	} //End of IF
	else
	{ 
		while (ptr->next != NULL) 
			ptr = ptr->next; 

		// Create new node dynamically 
		r = (struct Node *) malloc (sizeof(struct Node)); 
		r->value = v; 
		r->row_position = row; 
		r->column_postion = column; 
		r->next = NULL; 
		ptr->next = r; 

	}//End of ELSE
	return;
} //End of create_new_node function

// This function prints contents of linked list 
void Printtriples() 
{ 
	ptr = start;
	printf("\nThe values are going to be output as (i,j,aij)");
	//Printing all the nodes one by one
	while(ptr!=NULL){
		printf("\n(%d , %d ,%d)",ptr->row_position,ptr->column_postion,ptr->value);
		ptr = ptr->next;
			}
	return;
} //End of Printtriples function




