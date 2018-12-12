/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_iter_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:07:07 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 09:45:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		fra_iter_julia(t_fra_param *param, int x, int y)
{
	double	im;
	double	re;
	double	re2;
	double	im2;
	int		i;

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
