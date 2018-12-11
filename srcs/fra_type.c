/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:25:21 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:37:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

enum	e_fra_type	fra_type(char *str)
{
	if (str == 0)
		return (-1);
	if (ft_strcmp(ft_str_to_lower(str), "julia") != 0)
		return (0);
	if (ft_strcmp(ft_str_to_lower(str), "mandelbrot") != 0)
		return (1);
	return (ft_msg_int(2, "Invalid argument. Use Julia or Mandelbrot.\n", -1));
}
