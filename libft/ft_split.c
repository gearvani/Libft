/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:00:01 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/08/18 19:12:21 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, char sep)
{
	int	i;
	int	count_word;

	count_word = 1;
	i = 0;
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

void	len_word(int *word_len, const char *str, int x, char sep)
{
	while (str[x] != sep && str[x])
	{
		x++;
		(*word_len)++;
	}
}

char	*fill_word(int *x, const char *str, char sep, int *word_len)
{
	int		i;
	char	*result;

	i = 0;
	len_word (word_len, str, (*x), sep);
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

char	**ft_split(const char *str, char sep)
{
	char	**result;
	int		x;
	int		y;
	int		word_len;

	word_len = 0;
	x = 0;
	y = 0;
	while (str[x] == sep && str[x])
		x++;
	result = ft_calloc(word_count(str, sep), sizeof (char *));
	if (!result)
		return (NULL);
	while (str[x])
	{
		result[y] = fill_word(&x, str, sep, &word_len);
		if (!result[y])
			return (free_split(result));
		y++;
		word_len = 0;
		while (str[x] == sep && str[x])
			x++;
	}
	result[y] = NULL;
	return (result);
}
