/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/13 12:50:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <sys/time.h>
#include "libft.h"

static	void	test_perf(t_fra_param *param)
{
	double			t;
	struct timeval	t1;
	struct timeval	t2;

	param->qx = (double)DEFAULT_X_AMPLITUDE / (double)IMG_HEIGHT;
	param->qy = (double)DEFAULT_X_AMPLITUDE;
	param->zoom = 1;
	while (param->zoom < MAX_ZOOM)
	{
		param->qy /= ZOOM_INCR;
		param->qx /= ZOOM_INCR;
		param->zoom *= ZOOM_INCR;
	}
	param->o_re = 0.268056857839838391655;
	param->o_im = -0.126381839666804829391;
	param->num_max_iter = 410;
	gettimeofday(&t1, NULL);
	fra_draw(param);
	gettimeofday(&t2, NULL);
	t = (t2.tv_sec - t1.tv_sec) * 1000.0;
	t += (t2.tv_usec - t1.tv_usec) / 1000.0;
	ft_printf("time in ms: %f\n", t);
}

static	int		key_press2(int key, t_fra_param *param)
{
	if (key == 17)
		test_perf(param);
	if (key == 8)
		param->key_pressed2 = 1;
	if (key == 13)
		param->o_im = fra_pix_to_im(param, IMG_HEIGHT / 3);
	if (key == 0)
		param->o_re = fra_pix_to_re(param, IMG_WIDTH / 3);
	if (key == 1)
		param->o_im = fra_pix_to_im(param, IMG_HEIGHT * 2 / 3);
	if (key == 2)
		param->o_re = fra_pix_to_re(param, IMG_HEIGHT * 2 / 3);
	if (key == 0 || key == 1 || key == 2 || key == 13)
	{
		fra_draw(param);
		fra_print_stat(param);
	}
	return (0);
}

static	int		reset(int key, t_fra_param *param)
{
	if (key == 15)
	{
		param->qx = (double)DEFAULT_X_AMPLITUDE / (double)IMG_HEIGHT;
		param->qy = (double)DEFAULT_X_AMPLITUDE;
		param->zoom = 1;
		if (param->type != MANDELDROP)
		{
			param->o_re = 0;
			param->o_im = 0;
		}
		param->c_re = 0.3;
		param->c_im = 0.5;
		param->num_max_iter = DEFAULT_NUM_MAX_ITER;
		fra_draw(param);
		fra_print_stat(param);
		return (0);
	}
	return (0);
}

static	int		key_fra(int key, t_fra_param *param)
{
	if (key == 18)
	{
		param->type = JULIA;
		param->iter = &fra_iter_julia;
	}
	if (key == 19)
	{
		param->type = MANDELBROT;
		param->iter = &fra_iter_mandelbrot;
	}
	if (key == 20)
	{
		param->type = MANDELDROP;
		param->iter = &fra_iter_mandeldrop;
		param->o_re = 1.4;
		param->o_im = 0;
	}
	if (key == 21)
	{
		param->type = MANDEL2BROT;
		param->iter = &fra_iter_mandel2brot;
	}
	if (key == 18 || key == 19 || key == 20 || key == 21)
		reset(15, param);
	return (0);
}

int				fra_key_press(int key, void *arg)
{
	t_fra_param *param;

	param = (t_fra_param *)arg;
	if (key == 256)
		param->key_pressed = 1;
	if (key == 53)
	{
		fra_free_param(&param, 0, 11112);
		exit(0);
	}
	if (key == 23)
	{
		param->type = BURNING;
		param->iter = &fra_iter_burning_ship;
		reset(15, param);
	}
	key_fra(key, param);
	key_press2(key, param);
	reset(key, param);
	return (0);
}
