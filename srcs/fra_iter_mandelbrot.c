/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_iter_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:07:07 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 10:13:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fra_iter_mandelbrot(t_fra_param *param, int x, int y)
{
	double	c[2];
	double	z[2];
	double	re2;
	double	im2;
	int		i;

	i = 0;
	c[1] = fra_pix_to_im(param, y);
	c[0] = fra_pix_to_re(param, x);
	re2 = c[0] * c[0];
	im2 = c[1] * c[1];
	z[0] = c[0];
	z[1] = c[1];
	while (i <= param->num_max_iter && re2 + im2 < 4.0)
	{
		z[1] = (z[0] + z[1]) * (z[0] + z[1]) - re2 - im2 + c[1];
		z[0] = re2 - im2 + c[0];
		i++;
		im2 = z[1] * z[1];
		re2 = z[0] * z[0];
	}
	return (i);
}
