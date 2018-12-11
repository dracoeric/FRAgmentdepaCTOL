/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:50:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static	void	*draw(void *arg)
{
	int			x;
	int			y;
	t_fra_param	*param;

	param = (t_fra_param *)arg;
	y = 0;
	while ((y < IMG_HEIGHT))
	{
		x = param->n_thread;
		while (x < IMG_WIDTH)
		{
			mlx_pixel_put_img(param->img, x, y,
				param->cg(param, fra_iter_julia(param, x, y)));
			x += NUM_MAX_THREAD;
		}
		y++;
	}
	return (0);
}

void			fra_draw(t_fra_param *param)
{
	pthread_t	thread[NUM_MAX_THREAD];
	int 		i;

	i = 0;
	param->count = 0;
	ft_bzero(param->img->str, param->img->size_line * param->img->nb_line);
	while (i < NUM_MAX_THREAD)
	{
		param->n_thread = i;
		pthread_create(&thread[i], NULL, draw, param);		
		i++;
	}
	i = 0;
	while (i < NUM_MAX_THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->ptr, 0, 0);
}
