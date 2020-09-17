#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>


struct node {
int coef;
int exp;
struct node *link;
}*front,*rear,*new,*ptr1,*ptr,*x;

int main()
{
	int n;
	front = NULL;
	printf("\nEnter the degree of the polynomial");
	scanf("%d",&n);
	for(int i=0;i<n+1;i++) pread(i);
	rear->link = front;
	x = front;
	return 0;
}

void pread(){
	int coeff,expo;
	printf("\nEnter the coefficient and exponent of the %d term",i);
	scanf("%d %d",&coeff,&expo);
	if(coeff!=0){
	if(front == NULL){
		new = (struct node*)malloc(sizeof(struct node));
		new->coef = coeff;
		new->exp = exp;
		new->link = NULL;
		front = new;
		rear = new;
		}//END of IF statement for first node
	else{
		ptr = front;
		while(ptr->link!=NULL)
			ptr = ptr->link;
		new = (struct node*)malloc(sizeof(struct node));
		new->coef = coeff;
		new->exp = exp;
		new->link = NULL;
		ptr->link = new;
		rear = new;
		}//End of ELSE 
	}//End of IF checking for non zero coeff
}//End of pread fn
