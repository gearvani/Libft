/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:15:58 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/08/22 17:31:15 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int long n)
{
	int long	i;
	int			faktor;
	int			len;

	i = 1;
	faktor = 10;
	len = 0;
	if (n == 0)
		return(1);
	while (n >= i)
	{
		i = (i * faktor);
		len++;
	}
	return (len);
}

int long	pre_conv(int n, int *sign)
{
	int long	nbr;

	if (n < 0)
	{
		n = -n;
		(*sign) = 1;
	}
	nbr = n;
	return (nbr);
}

char	*is_pos(int nbr, int *i)
{
	char	*result;

	(*i) = nbr_len(nbr);
	result = malloc(nbr_len(nbr) + 1);
	if (!result)
		return (NULL);
	return (result);
}

char	*is_neg(int nbr, int *i)
{
	char	*result;

	(*i) = nbr_len(nbr) + 1;
	result = malloc(nbr_len(nbr) + 2);
	if (!result)
		return (NULL);
	result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*result;
	long int		nbr;
	int				sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	nbr = pre_conv(n, &sign);
	if (sign == 0)
		result = is_pos(nbr, &i);
	else if (sign == 1)
		result = is_neg(nbr, &i);
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (nbr == 0)
		result[i - 1] = '0';
	while (nbr != 0)
	{
		i--;
		result[i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	return (result);
}

/*int main()
{
	char *result = ft_itoa(-0);
	printf("%s", result);
	free(result);
}*/