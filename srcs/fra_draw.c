/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/10 15:38:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	fra_draw(t_fra_param *param)
{
	int	x;
	int	y;

	ft_bzero(param->img->str, param->img->size_line * param->img->nb_line + 1);
	y = 0;
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			mlx_pixel_put_img(param->img, x, y,
				param->cg(param, fra_iter_julia(param, x, y)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->ptr, 0, 0);
}
