/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_iter_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:07:07 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 12:44:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		fra_iter_julia(t_fra_param *param, int x, int y)
{
	long double	im;
	long double	re;
	long double re2;
	long double	im2;
	int			i;

	i = 0;
	im = fra_pix_to_im(param, y);
	re = fra_pix_to_re(param, x);
	im2 = 0;
	re2 = 0;
	while (i <= param->num_max_iter && re2 + im2 < 4.0)
	{
		re2 = re * re;
		im2 = im * im;
		im = 2 * re * im + param->c_im;
		re = re2 - im2 + param->c_re;
		i++;
	}
	return (i);
}
