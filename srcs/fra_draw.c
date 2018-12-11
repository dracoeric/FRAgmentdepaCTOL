/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:20:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:13:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	fra_draw(t_fra_param *param)
{
	pthread_t	thread1;
	pthread_t	thread2;
	pthread_t	thread3;
	pthread_t	thread4;
	pthread_t	thread5;

	param->p1 = 0;
	param->p2 = 0;
	param->p3 = 0;
	param->p4 = 0;
	param->p5 = 0;
	param->count = 0;
	ft_bzero(param->img->str, param->img->size_line * param->img->nb_line + 1);
	pthread_create(&thread1, NULL, fra_draw1, param);
	pthread_create(&thread2, NULL, fra_draw2, param);
	pthread_create(&thread3, NULL, fra_draw3, param);
	pthread_create(&thread4, NULL, fra_draw4, param);
	pthread_create(&thread5, NULL, fra_draw5, param);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img->ptr, 0, 0);
}
