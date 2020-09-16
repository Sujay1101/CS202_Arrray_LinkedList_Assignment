#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int choice,i,pos,item;
struct node {
	int data;
	struct node *link;
}*header,*ptr,*ptrpre,*new,*x,*p;

void insertion();
void delete_node();
int main()
{
	header=NULL;
	ptr=header;
	p = header;
	printf("****Menu****\n");
	printf("\n 1.Insertion\n 2.Delete a node\n 3.Exit\n");
	while(1) {
	printf("\nEnter ur choice");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
				insertion();
				break;
		case 2:
				if(header == NULL){ printf("\nwrong choice , Linked List is empty . Please insert data first.\n");continue;}
				else delete_node();
				break;
		case 3:
				exit();
		default: printf("\nwrong choice\n");
		}/*end of switch*/
	}/*end of while*/
	return 0;
}/*end of main*/

void delete_node(){
	ptr=header;
	p = header;
	printf("\nNow enter the element that you want to delete");
	scanf("%d",&item);
	while(ptr->data != item){
		ptr = ptr->link;
		}/*end of while*/
	while(
	if ( x == p) { 
		printf("\nI have just deleted %d ",header->data);
		header = header->link;
		
		}
	else{
		while(x!=ptr){
			ptrpre = ptr;
			ptr = ptr->link;
			}/*end of while*/
			printf("\nI have just deleted %d ",ptr->data);
			ptrpre ->link = ptr->link;
		}/*end of else*/
	}/*end of delete_node fn*/

void insertion(){
	new=(struct node *)malloc(sizeof(struct node));
	printf("\n enter the item to be inserted\n");
	scanf("%d",&item);
	new->data=item;
	if(header = = NULL)
		{
			new->link=NULL;
			header=new;
		}/*end of if*/
	printf("\n enter the next item to be inserted\n");	
	scanf("%d",&item);
	ptr=header;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	new=(struct node *)malloc(sizeof(struct node));
	new->link=NULL;
	ptr->link=new;
	printf("\nIf you are done inserting data into linked list, enter 3 . Else enter anything else");
	scanf("%d",&item);
	if(item == 3 ) return NULL;
	else insertion();	
	}/*end of Insertion fn*/
