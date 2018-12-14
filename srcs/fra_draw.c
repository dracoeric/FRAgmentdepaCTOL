/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 10:26:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <sys/time.h>
#include "libft.h"

static	void	draw_loop(t_fra_param *param, int x0)
{
	int y;
	int x;

	y = 0;
	while ((y < IMG_HEIGHT))
	{
		x = x0;
		while (x < IMG_WIDTH)
		{
			mlx_pixel_put_img(param->img, x, y,
				param->cg(param, param->iter(param, x, y)));
			x += NUM_MAX_THREAD;
		}
		y++;
	}
}

static	void	*draw(void *arg)
{
	int				x0;
	t_fra_param		*param;
	struct timeval	t[2];

	param = (t_fra_param *)arg;
	x0 = 0;
	while (pthread_self() != (param->thread0)[x0])
		x0++;
	if (gettimeofday(t, NULL) == -1)
		return (ft_msg_ptr(0, "gettimeofday error.\n", 0));
	draw_loop(param, x0);
	if (gettimeofday(t + 1, NULL) == -1)
		return (ft_msg_ptr(0, "gettimeofday error.\n", 0));
	if (x0 >= 0 && x0 < NUM_MAX_THREAD)
	{
		(param->thread_time)[x0] = (t[1].tv_sec - t[0].tv_sec) * 1000.0;
		(param->thread_time)[x0] += (t[1].tv_usec - t[0].tv_usec) / 1000.0;
	}
	return (0);
}

void			fra_draw(t_fra_param *param)
{
	pthread_t	thread[NUM_MAX_THREAD];
	int			i;

	i = 0;
	param->count = 0;
	param->thread0 = thread;
	while (i < NUM_MAX_THREAD)
	{
		if (pthread_create(&thread[i], NULL, draw, param) == -1)
			return ;
		i++;
	}
	i = 0;
	while (i < NUM_MAX_THREAD)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return ;
		i++;
	}
	param->thread0 = NULL;
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img->ptr, 0, 0);
}
