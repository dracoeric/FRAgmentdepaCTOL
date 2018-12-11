/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 13:04:16 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static	void	incr_pix(t_fra_param *param, int x)
{
	if (x == IMG_WIDTH)
	{
		param->mutex->py++;
		param->mutex->px = 0;
	}
	else
		param->mutex->px++;
}

void	draw(t_fra_param *param)
{
	int	x;
	int	y;

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
}

void	*draw1(void *arg)
{
	int	x;
	int	y;
	t_fra_param *param;

	param = (t_fra_param *)arg;
	pthread_mutex_lock(&(param->mutex->mutex));
	x = param->mutex->px;
	y = param->mutex->py;
	incr_pix(param, x);
	pthread_mutex_unlock(&(param->mutex->mutex));
	while ((y < IMG_HEIGHT))
	{
		mlx_pixel_put_img(param->img, x, y,
			param->cg(param, fra_iter_julia(param, x, y)));
		pthread_mutex_lock(&(param->mutex->mutex));
		x = param->mutex->px;
		y = param->mutex->py;
		incr_pix(param, x);
		pthread_mutex_unlock(&(param->mutex->mutex));
	}
	pthread_exit(NULL);
}

void	fra_draw(t_fra_param *param)
{
	pthread_t	thread1;
//	pthread_t	thread2;
//	pthread_t	thread3;
//	pthread_t	thread4;

	ft_bzero(param->img->str, param->img->size_line * param->img->nb_line + 1);
	pthread_create(&thread1, NULL, draw1, param);
//	pthread_create(&thread2, NULL, draw, param);
//	pthread_create(&thread3, NULL, draw, param);
//	pthread_create(&thread4, NULL, draw, param);
	pthread_join(thread1, NULL);
//	pthread_join(thread2, NULL);
//	pthread_join(thread3, NULL);
//	pthread_join(thread4, NULL);
//	draw(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->ptr, 0, 0);
}
