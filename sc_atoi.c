#include <unistd.h>
#include <stdio.h>

int sc_atoi(char *str)
{
	int i = 0;
	int sinal = 1;
	int result = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal *= -1; //sinal = sinal * (-1)
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sinal);
}

int main(void)
{
	char str[] = "  	   --------122b548aa";
	int i;

	i = sc_atoi(str);
	printf("Int: %i\n", i);

	return 0;
}