/*ZIEL = einen string in meherere strings zu splitten mit einem beliebigen seperator und in einen 2d array zu speichern!


berrechne die groesse von dem 2d array-groesse der Y achse (also wie viele strings)-der seperator gibt an wie viele strings wir haben-groesse der x achse (also wie gross jeder string ist)

den 2d array zu befuellen

malloc oder calloc protection!

wenn fehlschlaegt free alles was du bereits allokiert hast!

beispiel: string = "Hallo0Welt" seperator = '0';

array[0] = Hallo;
array[1] = Welt;*/

#include "libft.h"


int word_count(const char *str, char sep)
{
	int i;
	int count_word;

	count_word = 1;
	i = 0;
	while(str[i])
	{
		if(str[i] == sep)
		{
			while(str[i] == sep && str[i])
			{
				i++;
			}
			if(str[i] == '\0')
				break;
			count_word++;
		}
		i++;
	}
	return(count_word);
}

void fill_word(int x, char *result, const char *str, char sep)
{
	int i;

	i = 0;
	while(str[x] && str[x] != sep)
	{
		result[i] = str[x];
		x++;
		i++;
	}
}

void *free_split(char **result)
{
	int y;

	y = 0;
	while(result[y])
	{
		free(result[y]);
		y++;
	}
	free(result);
	return(NULL);
}

void len_word(int *word_len, const char *str, int *x, char sep)
{
	int i;

	i = 0;
	while(str[(*x)] != sep && str[(*x)])
	{
		(*x)++;
		(*word_len)++;
	}
}
int skip_sep(const char *str,char sep)
{
	int i;

	i = 0;
	while(str[i] == sep)
	{
		i++;
	}
	return(i);
}


char **ft_split(const char *str, char sep)
{
	char **result;
	int x;
	int y;
	int word_len;

	word_len = 0;
	x = skip_sep(str, sep);
	y = 0;
	result = ft_calloc(word_count(str, sep), sizeof(char *));
	if(!result)
		return(NULL);
	while(str[x])
	{
		len_word(&word_len, str, &x, sep);
		result[y] = ft_calloc (word_len, sizeof(char));
		if(!result[y])
			return (free_split(result));
		fill_word(x - word_len, result[y], str, sep);
		y++;
		word_len = 0;
		while(str[x] == sep && str[x])
			x++;
	}
	result[y] = NULL;
	return(result);
}
/*int main()
{
	int i;

	i = 0;
	char **result = ft_split("             ", ' ');
	while(result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	int y;

	y = 0;
	while(result[y])
	{
		free(result[y]);
		y++;
	}
	free(result);
}*/

