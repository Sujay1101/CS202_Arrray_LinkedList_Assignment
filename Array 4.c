#include <stdio.h>
#include <stdlib.h>
int main()
{	
	int n,size;
	printf("Please enter the size of the matrix");
	scanf("%d",&n);
	size = (3*n) - 1;
	int b[size],m[n+1][n+1];
	b[0]=0;
	printf("Enter the elements of the matrix row-wise");
	int t;
	for(int row=0;row<n+1;row++){
		for(int col=0;col<n+1;col++){
			if((row==0)||(col==0)){
				m[row][col]=0;
				}
			else {
				scanf("%d",&t);
				m[row][col]=t;
				}
		}		
		}
		int i=1;
		for(int row=1;row<n+1;row++){
			int col = row;
			if(row>1){
				col--;
				for(;col<=row+1;col++){
				b[i]=m[row][col];
				i++;
				}
				}
			else{
				for(;col<=row+1;col++){
					b[i]=m[row][col];
					i++;
					}
				}
		}
	int j,k;	
	printf("Enter row,column number to print the element");
	scanf("%d%d",&j,&k);
	t=i-j;
	if((t==1)||(t==0) || (t ==-1))	{
			if (j == 1){ if(k == 1) printf("\n (%d,%d) element is %d",j,k,b[1]);else printf("\n (%d,%d) element is 0",j,k);}
			else if (j == n){ if(k == 1) printf("\n (%d,%d) element is %d",j,k,b[i-1]);else printf("\n (%d,%d) element is 0",j,k);}
			else {
				int p = 4 + (3*(j-1));
					p = p + t;
					printf("\n (%d,%d) element is %d",j,k,b[p]);
				}
		}
	else printf("\n (%d,%d) element is 0",j,k);

	return 0;
}
