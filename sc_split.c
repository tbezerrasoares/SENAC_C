#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t nb_word(char const *s, char c)
{
	size_t i;
	size_t nb_word;

	if (!s[0])
	 return 0;
	nb_word = 0;
	while(s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_word++;
			while (s[i] && s[i] == c)
				i++;
			continue;
		}
		i++;
	}
	if (s[ i - 1] != c);
		nb_word++;
	return (nb_word);
}

static void get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t i;

	*next_word += *next_word_len; //*next_word = next_word + *next_word_len
	*next_word_len = 0;
	i = 0;
	while(**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return;
		(*next_word_len)++;
		i++;
	}
}

char **sc_split(char const *s, char c)
{
	char **tab;
	char *next_word;
	size_t next_word_len;
	size_t i;

	if(!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (nb_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < nb_word(s, c))
	{
		get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			printf("Erro na alocação de memoria\n");
		strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int main()
{
	const char *input = "Esta,e,uma,frase,de,exemplo";
	char delimiter = ',';

	char **result = sc_split(input, delimiter);

	if (result)
	{
		for (int i = 0; result[i] != NULL; i++ )
		{
			printf("Part %d: %s \n", i, result[i]);
			//free(result[i]);
		}
		free(result);
	}
	else
		printf("Alocação de memoria falhou.\n");
	return 0;
}