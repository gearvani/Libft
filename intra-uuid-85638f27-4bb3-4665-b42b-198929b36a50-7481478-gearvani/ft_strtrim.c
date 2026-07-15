/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login <login@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+   */
/*   Created: 2026/07/10 12:55:00 by login             #+#    #+#             */
/*   Updated: 2026/07/10 12:55:00 by login            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*create_trimmed_str(char const *s1, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	if (start > end)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (end > start && is_in_set(s1[end], set))
		end--;
	return (create_trimmed_str(s1, start, end));
}

int	main(void)
{
	char	*res1;

	// Test 1: Standard trimming of spaces and tabs
	res1 = ft_strtrim("Hello, 42 Network!\n", "he");
	printf("Test 1 (Standard):\nExpected: 'Hello, 42 Network!'\nResult:   '%s'\n\n", res1);
	free(res1);

	return (0);
}
