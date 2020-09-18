#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

int sumto(int);
int b[10000];
int main()
{
	int i,j,n,t=0;
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
			a[i][j] = item;
			}
		}
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			if(i<=j){
				b[t] = a[i][j];
				t++;
				}
			}
		}
	printf("\nEnter the row and column i.e (i,j) to retrieve from b-array");
	scanf("%d %d ",&i,&j);
	t = sumto(i-1) + j;
	printf("\n The element at (i,j) is %d",b[t]);
	return 0;
}//End of main

int sumto(int a){
	int sum=0;
	for(int x=0;x<=a;x++) sum = sum + a;
	return sum;
	}

