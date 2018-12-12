/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 09:25:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <time.h>

static	void	*draw(void *arg)
{
	int			x;
	int			y;
	int			x0;
	t_fra_param	*param;
	double		t;

	param = (t_fra_param *)arg;
	y = 0;
	x0 = 0;
	t = clock();
	while (pthread_self() != (param->thread0)[x0])
		x0++;
	while ((y < IMG_HEIGHT))
	{
		x = x0;
		while (x < IMG_WIDTH)
		{
			mlx_pixel_put_img(param->img, x, y,
				param->cg(param, fra_iter_julia(param, x, y)));
			x += NUM_MAX_THREAD;
		}
		y++;
	}
	(param->thread_time)[x0] = (double)(clock() - t)/CLOCKS_PER_SEC;
	return (0);
}

void			fra_draw(t_fra_param *param)
{
	pthread_t	thread[NUM_MAX_THREAD];
	int 		i;

	i = 0;
	param->count = 0;
	param->thread0 = thread;
	while (i < NUM_MAX_THREAD)
	{
		pthread_create(&thread[i], NULL, draw, param);		
		i++;
	}
	i = 0;
	while (i < NUM_MAX_THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	param->thread0 = NULL;
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->ptr, 0, 0);
}
