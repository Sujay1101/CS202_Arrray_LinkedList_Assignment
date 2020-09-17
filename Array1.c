//Problem 1 in arrays
//Write a programme to multiply two polynomials using array representation. What is time complexity?
//Time complexity is O(mn) where m and n represent degree of both the polynomials

#include <stdio.h>
#include <stdlib.h>

float* poly_multi(float*, float*, int, int);
void initialise_poly(float**, int*);

int main()
{
	int pdeg, qdeg;
	float* p, * q;

	//Initialising the polynomials 
	initialise_poly(&p, &pdeg);
	initialise_poly(&q, &qdeg);

	//Calculating product of two polynomials
	float* prod = poly_multi(p, q, pdeg, qdeg);

	for (int i = 0; i != pdeg + qdeg + 1; ++i)
		printf("%.3f  ", prod[i]);

	//Freeing all three memory occupied by all three polynomials
	free(prod);
	free(p);
	free(q);
}

//Takes as argument two arrays representing coefficients of two polynomials 
//and returns coefficient array of multiplication of the two polynomials
float* poly_multi(float* p, float* q, int pdeg, int qdeg)
{
	int deg = pdeg + qdeg;
	float* prod = (float*)malloc(sizeof(float) * (deg + 1));
	if (prod == NULL)
		return NULL;

	for (int i = 0; i != deg + 1; ++i)
	{
		prod[i] = 0;
		for (int r = i - pdeg > 0 ? i - pdeg : 0; r <= qdeg && r <= i; ++r)
			prod[i] += p[i - r] * q[r];
	}
	return prod;
}

//Initialises polynomial. poly is the address of the pointer which will point to coefficient array of polynomial
void initialise_poly(float** poly, int* deg)
{
	printf("Enter the degree of polynomial\n");
	scanf_s("%d", deg);
	*poly = (float*)malloc(sizeof(float) * (*deg + 1));
	printf("Enter the coefficients of the polynomial in ascending order of exponent\n");
	for (int i = 0; i != *deg + 1; ++i)
		scanf_s("%f", *poly + i);
}
