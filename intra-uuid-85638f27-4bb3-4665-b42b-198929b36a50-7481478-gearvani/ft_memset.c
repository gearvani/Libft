/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gearvani <gearvani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:45:27 by gearvani          #+#    #+#             */
/*   Updated: 2026/07/01 16:57:06 by gearvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
	char *temp;

	temp = s;
	while(n--)
	{
		*temp = c;
		temp++;
	}
	return(s);
}













// void *ft_memset(void *s, int c, size_t n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (n > 0)
// 	{
// 		*p = (unsigned char)c;
// 		p++;
// 		n--;
// 	}
// 	return (s);
// }

// int main()
// {
//     char str1[50] = "GeeksForGeeks is for programming geeks.";
//     char str2[50] = "GeeksForGeeks is for programming geeks.";
    
// 	printf("\nBefore ft_memset(): %s\n", str1);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str1 + 13, '.', 8*sizeof(char));

//     printf("After ft_memset():  %s", str1);

// 	printf("\nBefore memset(): %s\n", str2);

//     // Fill 8 characters starting from str[13] with '.'
//     memset(str2 + 13, '.', 8*sizeof(char));

//     printf("After memset():  %s", str2);
    
//     return 0;
// }