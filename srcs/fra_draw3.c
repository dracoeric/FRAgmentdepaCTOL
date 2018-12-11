/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:06:02 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:12:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*fra_draw3(void *arg)
{
	int			x;
	int			y;
	t_fra_param	*param;

	param = (t_fra_param *)arg;
	y = 0;
	while ((y < IMG_HEIGHT))
	{
		x = 2;
		while (x < IMG_WIDTH)
		{
			mlx_pixel_put_img(param->img, x, y,
				param->cg(param, fra_iter_julia(param, x, y)));
			param->p3++;
			x += 5;
		}
		y++;
	}
	return (0);
}
