#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Quantidade de argumentos: %i\n", argc);
	if (argc != 4)
	{
		printf("Erro ! Numero de argumentos invalidos.\n");
		return 0;
	}
	else
	{
		int i = 0;
		while(i < 4)
		{
			printf("Argumento %i: %s\n", i, argv[i]);
			i++;
		}
	}
	return 0;
}