/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:00:01 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/08/21 18:03:50 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char sep)
{
	int	i;
	int	count_word;

	count_word = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == sep)
		{
			while (str[i] == sep && str[i])
			{
				i++;
			}
			if (str[i] == '\0')
				break ;
			count_word++;
		}
		i++;
	}
	return (count_word);
}

char	*fill_word(int *x, const char *str, char sep, int *word_len)
{
	int		i;
	char	*result;
	int		y;

	y = 0;
	i = 0;
	while (str[*x + y] != sep && str[*x + y])
	{
		y++;
		(*word_len)++;
	}
	result = ft_calloc (((*word_len) + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (str[(*x)] && str[(*x)] != sep)
	{
		result[i] = str[(*x)];
		(*x)++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	*free_split(char **result)
{
	int	y;

	y = 0;
	while (result[y])
	{
		free(result[y]);
		y++;
	}
	free(result);
	return (NULL);
}

int skip_sep(const char *str, char sep, int pos)
{
	while (str[pos] == sep && str[pos])
		pos++;
	return(pos);
}

char	**ft_split(const char *str, char sep)
{
	char	**result;
	int		x;
	int		y;
	int		word_len;

	word_len = 0;
	x = 0;
	y = 0;
	if (!str)
		return (NULL);
	x = skip_sep(str, sep, x);
	result = ft_calloc(word_count(str, sep) + 1, sizeof (char *));
	if (!result)
		return (NULL);
	while (str[x])
	{
		result[y] = fill_word(&x, str, sep, &word_len);
		if (!result[y])
			return (free_split(result));
		y++;
		word_len = 0;
		x = skip_sep(str, sep, x);
	}
	return (result);
}


/*int main()
{
	int i;
	i = 0;
	char **result = ft_split("Hallo", 'l');
	if (!result)
		return (1);
	while (result[i])
	{
		printf("%s", result[i]);
		i++;
	}
	free_split(result);
}*/
