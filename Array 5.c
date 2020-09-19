//Problem 5 in arrays
#include <stdio.h>
#include <stdlib.h>

void print_saddle_points(int **, int, int);
int max_of_array(int *, int);
int min_of_array(int *, int);

int main()
{
	int m, n;
	printf("Enter the size of matrix as m,n\n");
	scanf_s("%d%d", &m, &n);

	//Allocating memory for a 2D array
	int **matrix = (int **)malloc(sizeof(int *) * m);
	for (int i = 0; i != m; ++i)
		matrix[i] = (int *)malloc(sizeof(int) * n);

	printf("Enter the numbers of the matrix row wise\n");
	for (int i = 0; i != m; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			scanf_s("%d", &matrix[i][j]);
		}
	}
	print_saddle_points(matrix, m, n);
}
//Function returns index of maximum element of array
int max_of_array(int* arr, int len)
{
	int max = 0;
	for (int i = 0; i != len; ++i)
	{
		if (arr[max] < arr[i])
			max = i;
	}
	return max;
}
//Function returns index of minimum element of array
int min_of_array(int* arr, int len)
{
	int min = 0;
	for (int i = 1; i != len; ++i)
	{
		if (arr[min] > arr[i])
			min = i;
	}
	return min;
}
//Function prints position of saddle point if one exists 
void print_saddle_points(int** matrix, int m, int n)
{
	//minima_index - array to store horizontal positions of minimas of all rows
	int *minima_index = (int *)malloc(sizeof(int) * m);

	//minima - array to store values of elements which are minimas of all rows 
	int *minima = (int *)malloc(sizeof(int) * m);

	//Storing appropriate values in minima and minima_index array
	for (int i = 0; i != m; ++i)
	{
		minima_index[i] = min_of_array(matrix[i], n);
		minima[i] = matrix[i][minima_index[i]];
	}
	//Saddle point can only occur at the maximum element of minima array
	int saddle_max = max_of_array(minima, m);
	int j = 0;

	//Checking whether the point is maximum of its column
	for (j = 0; j != m; ++j)
	{
		if (matrix[j][minima_index[saddle_max]] > minima[saddle_max])
			break;
	}
	//If it exists printing the position of the element
	if (j == m)
		printf("%d %d\n", saddle_max, minima_index[saddle_max]);
}

