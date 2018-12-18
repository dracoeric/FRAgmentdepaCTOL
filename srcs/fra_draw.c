/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/18 16:19:11 by erli             ###   ########.fr       */
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
	int				x_o;
	t_fra_param		*param;
	struct timeval	t[2];

	param = (t_fra_param *)arg;
	x_o = 0;
	pthread_mutex_lock(&(param->mutex));
	while (pthread_self() != (param->thread0)[x_o] && x_o < NUM_MAX_THREAD)
		x_o++;
	pthread_mutex_unlock(&(param->mutex));
	if (gettimeofday(t, NULL) == -1)
		return (ft_msg_ptr(0, "gettimeofday error.\n", 0));
	draw_loop(param, x_o);
	if (gettimeofday(t + 1, NULL) == -1)
		return (ft_msg_ptr(0, "gettimeofday error.\n", 0));
	if (x_o >= 0 && x_o < NUM_MAX_THREAD)
	{
		(param->thread_time)[x_o] = (t[1].tv_sec - t[0].tv_sec) * 1000.0;
		(param->thread_time)[x_o] += (t[1].tv_usec - t[0].tv_usec) / 1000.0;
	}
	return (0);
}

void			fra_draw(t_fra_param *param)
{
	pthread_t	thread[NUM_MAX_THREAD];
	int			i;

	if (param == 0)
		return ;
	i = 0;
	param->thread0 = thread;
	pthread_mutex_lock(&(param->mutex));
	while (i < NUM_MAX_THREAD)
	{
		if (pthread_create(&thread[i], NULL, draw, param) == -1)
			return ;
		i++;
	}
	pthread_mutex_unlock(&(param->mutex));
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
