/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_iter_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:07:07 by erli              #+#    #+#             */
/*   Updated: 2018/12/17 16:12:54 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fra_iter_julia(t_fra_param *param, int x, int y)
{
	double	im;
	double	re;
	double	re2;
	double	im2;
	int		i;

	if (param == 0)
		return (0);
	i = 0;
	im = fra_pix_to_im(param, y);
	re = fra_pix_to_re(param, x);
	re2 = re * re;
	im2 = im * im;
	param->count++;
	while (i <= param->num_max_iter && re2 + im2 < 4.0)
	{
		im = (re + im) * (re + im) - re2 - im2 + param->c_im;
		re = re2 - im2 + param->c_re;
		i++;
		im2 = im * im;
		re2 = re * re;
	}
	return (i);
}
