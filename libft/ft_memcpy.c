/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:37:23 by gearvani          #+#    #+#             */
/*   Updated: 2026/08/05 14:42:22 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	i;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (n > i)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (temp_dest);
}

// void *ft_memcpy(void *dest, const void *src, size_t n)
// {
//     while (n--)
//     {
//         *(char *)dest++ = *(const char *)src++;
//     }
// }

// int main()
// {
//     char src1[] = "Hello world";
//     char dest1[] = "world hello";
//     printf("======test======\n\n%s\n\n",dest1);
//     ft_memcpy(dest1, src1, 11);
//     printf("%s\n",dest1);

//     char src2[] = "Hello world";
//     char dest2[] = "world hello";
//     printf("%s\n\n",dest2);
//     memcpy(dest2, src2, 11);
//     printf("%s\n",dest2);
// }