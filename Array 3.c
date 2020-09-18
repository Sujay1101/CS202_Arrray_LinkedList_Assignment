#include <stdio.h>
#include <stdlib.h>

void initialise_array(int*, int);
void combine_matrices(int*, int*, int **, int);

int main()
{
	int *low, *up;
	int n;
	printf("Enter the dimension of the matrix\n");
	scanf_s("%d", &n);

	low = (int *)malloc(sizeof(int) * (n * (n + 1)) / 2);
	up = (int *)malloc(sizeof(int) * (n * (n + 1)) / 2);

	int **comb = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i != n; ++i)
		comb[i] = (int *)malloc(sizeof(int) * (n + 1));

	//Initialising lower triangular matrix
	printf("Enter the lower elements of the lower triangular matrix row wise\n");
	initialise_array(low, n * (n + 1) / 2);

	//Initialising upper triangular matrix
	printf("Enter the upper elements of the upper triangular matrix row wise\n");
	initialise_array(up, n * (n + 1) / 2);

	combine_matrices(up, low, comb, n);

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != (n + 1); ++j)
			printf("%d ",comb[i][j]);
		printf("\n");
	}
	return 0;
}
//Function to initialise array
void initialise_array(int* arr, int len)
{
	for (int i = 0; i != len; ++i)
	{
		scanf_s("%d", arr + i);
	}
}
//Function to combine lower and upper triangular matrices
void combine_matrices(int* up, int* low, int** comb, int n)
{
	int count_up = 0;
	int count_low = 0;
	//Invariant: [0,i) rows of comb initialised
	for (int i = 0; i != n; ++i)
	{
		int j;
		//Invariant count_low elements from low array initialised into comb
		for (j = 0; j != i + 1; ++j)
		{
			comb[i][j] = low[count_low];
			++count_low;
		}
		//Invariant count_up elements from up array initialised into comb
		for (; j != n + 1; ++j)
		{
			comb[i][j] = up[count_up];
			++count_up;
		}
	}
}