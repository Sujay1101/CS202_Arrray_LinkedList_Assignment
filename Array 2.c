#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int sumto(int);
int b[10000];
int main()
{
	int i,j,n,t=0,item,k,l;
	b[0] = 0;
	printf("\nEnter the number of rows");
	scanf("%d",&n);
	int a[n+1][n+1];
	for(i=0;i<1;i++){for(j=0;j<n+1;j++) a[i][j]=0;}
	for(j=0;j<1;j++){for(i=0;i<n+1;i++) a[i][j]=0;}
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			printf("\nEnter the element in (%d,%d)",i,j);
			scanf("%d",&item);
			fflush(stdin);
			a[i][j] = item;
			}
		}
		t=1;
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			if(i<=j){
				b[t] = a[i][j];
				t++;
				}
			}
		}
	printf("\nEnter the row and column i.e (i,j) to retrieve from b-array");
	scanf("%d%d",&k,&l);
	printf("%d %d",k,l);
	if( (k>i) || (l>j)) { printf("\nWrong Input"); exit(0);}
	else{
	t = 0 ;
	t = sumto(k-1) + l;			//We stored it in such a way that (i,j) element of matrix is at b[t] where t = 1+2+3+...+i-1 + j
	fflush(stdin);
	printf("\n The element at (%d,%d) is %d",k,l,b[t]);}
	return 0;
}//End of main

int sumto(int a){			//This function calculates sum of all natural numbers upto 'a' along with 'a'
	int sum=0;
	for(int x=0;x<=a;x++) sum = sum + a;
	return sum;
	}//End of sumto function

