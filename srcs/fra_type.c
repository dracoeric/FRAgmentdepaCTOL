/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:25:21 by erli              #+#    #+#             */
/*   Updated: 2018/12/13 14:38:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

enum	e_fra_type	fra_type(char *str)
{
	if (str == 0)
		return (5);
	if (ft_strcmp(ft_str_to_lower(str), "julia") == 0)
		return (JULIA);
	if (ft_strcmp(ft_str_to_lower(str), "mandelbrot") == 0)
		return (MANDELBROT);
	if (ft_strcmp(ft_str_to_lower(str), "mandeldrop") == 0)
		return (MANDELDROP);
	if (ft_strcmp(ft_str_to_lower(str), "mandel2brot") == 0)
		return (MANDEL2BROT);
	if (ft_strcmp(ft_str_to_lower(str), "burning") == 0)
		return (BURNING);
	ft_msg_int(2, "Invalid argument. Use Julia, Mandelbrot, Mandeldrop,", 0);
	return (ft_msg_int(2, " Mandel2brot or Burning.\n", -1));
}
