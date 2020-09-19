//Problem 11 of linked list
//Multiply two polynomials represented by circular linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct term
{
	int coeff;
	int exp;
	struct term* next;
}term;

typedef struct poly {
	term* first;
	term* last;
}poly;

poly initialise();
int append(poly *, int);
void poly_multi(poly, poly);
void print_poly(poly);
poly array_to_circular_list(int*, int);

poly a, b, c;
int m, n;

int main()
{
	a = initialise();
	b = initialise();
	c = initialise();
	int coeff;
	printf("Enter the degree of first polynomial\n");
	scanf_s("%d", &m);
	printf("Enter the coefficients of the first polynomial in ascending order\n");
	for (int i = 0; i != m + 1; ++i)
	{
		scanf_s("%d", &coeff);
		if (!append(&a, coeff))
		{
			printf("Error! Please Enter the number again\n");
		}
	}
	printf("Enter the degree of second polynomial\n");
	scanf_s("%d", &n);
	printf("Enter the coefficients of the second polynomial in ascending order\n");
	for (int i = 0; i != n + 1; ++i)
	{
		scanf_s("%d", &coeff);
		if (!append(&b, coeff))
		printf("Error! Please Enter the number again\n");
	}
	poly_multi(a, b);
	printf("The coefficients of the product polynomial in increasing order are\n");
	print_poly(c);
	return 0;
}

void poly_multi(poly a, poly b)
{
	//Initialising all the values in array to zero
	int* mul = (term*)malloc(sizeof(term) * (m + n + 1));
	for (int i = 0; i != m + n + 1; ++i)
		mul[i] = 0;
	//Traversing both the circular linked list and incrementing coefficients of product polynomial
	term* pa = a.first;
	term* pb = b.first;
	do
	{
		do
		{
			mul[pa->exp + pb->exp] += pa->coeff * pb->coeff;
			pb = pb->next;
		} while (pb != b.first);
		pa = pa->next;
	} while (pa != a.first);

	c = array_to_circular_list(mul, m + n + 1);
}
//Converts array into polynomial represented by circular linked list 
poly array_to_circular_list(int* arr, int size)
{
	poly p = initialise();
	for (int i = 0; i != m + n + 1; ++i)
		append(&p, arr[i]);
	return p;
}
//Initialises polynomial
poly initialise()
{
	poly x ;
	x.first = NULL;
	x.last = NULL;
	return x;
}
//Appends a term to polynomial
int append(poly *ptr, int coeff)
{
	term* new = (term*)malloc(sizeof(term));
	if (new == NULL)
		return 0;
	new->coeff = coeff;
	if (ptr->first == NULL)
	{
		new->exp = 0;
		ptr->first = new;
	}
	else
	{
		new->exp = ptr->last->exp + 1;
		ptr->last->next = new;
	}

	ptr->last = new;
	new->next = ptr->first;
	return 1;
}
//Prints the coefficients of the polynomial in ascending order of exponents
void print_poly(poly p)
{
	term* ptr = p.first;
	if (ptr == NULL)
		printf("Polynomial has no terms\n");
	do
	{
		printf("%d ",ptr->coeff);
		ptr = ptr->next;
	} while (ptr != p.first);
	putchar('\n');
	return;
}



