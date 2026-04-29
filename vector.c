#include <unistd.h>
#include <stdio.h>

void sc_vector(int *nbr)
{
	*nbr = 42;
}

int main(void)
{
	int nbr = 0;

	printf("Before: %d\n", nbr);
	sc_vector(&nbr);
	printf("After: %d\n", nbr);
	return 0;
}