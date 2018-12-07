/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:19:28 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 15:13:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static	int		max_power(long double nb, long double *pow)
{
	int n_pow;

	n_pow = 0;
	if (nb < 0)
		*pow = -1;
	if (nb == -2147483648)
	{
		*pow *= 10;
		n_pow++;
	}
	while (nb / *pow >= 10)
	{
		*pow *= 10;
		n_pow++;
	}
	return (n_pow);
}

char			*ft_itoa(long double nb)
{
	long double	pow;
	int			i;
	char		*str;

	pow = 1;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (max_power(nb, &pow) + 2))))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		i++;
	}
	while (pow != 0)
	{
		str[i] = (int)(nb / pow) + 48;
		nb = (nb - (str[i] - 48)) / 10;
		pow /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
