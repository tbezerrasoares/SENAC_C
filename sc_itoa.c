#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int sc_neg(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int sc_sizecal(int n)
{
	int size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while(n != 0)
	{
		n = n / 10;
		size++;
	}
	return size;
}

char *ft_itoa(int n)
{
	int num;
	char *res;
	int size;

	num = sc_neg(n);
	size = sc_sizecal(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

int main(void)
{
	char	*res;

	printf("--- TESTES FT_ITOA ---\n\n");

	// Teste 1: Número positivo padrão
	res = ft_itoa(42);
	printf("Esperado: 42         | Obtido: %s\n", res);
	free(res);

	// Teste 2: Número zero
	res = ft_itoa(0);
	printf("Esperado: 0          | Obtido: %s\n", res);
	free(res);

	// Teste 3: Número negativo padrão
	res = ft_itoa(-1234);
	printf("Esperado: -1234      | Obtido: %s\n", res);
	free(res);
}