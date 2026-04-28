#include <unistd.h>

void sc_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	char str[] = "HellO, World!@[[]]";
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		sc_putchar(str[i]);
		i++;
	}
	sc_putchar('\n');
	return 0;
}