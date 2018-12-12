/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 14:04:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <time.h>
#include "libft.h"

static	int		key_press2(int key, t_fra_param *param)
{
	double t;

	if (key == 17)
	{
		t = clock();
		fra_draw(param);
		t = (double)(clock() - t) / CLOCKS_PER_SEC;
		ft_printf("draw time: %f at zoom = %f\n", t, param->zoom);
	}
	return (0);
}

int				fra_key_press(int key, void *arg)
{
	t_fra_param *param;

	param = (t_fra_param *)arg;
	if (key == 256)
		param->key_pressed = 1;
	if (key == 15)
	{
		param->qx = (double)DEFAULT_X_AMPLITUDE
			/ (double)IMG_HEIGHT;
		param->qy = (double)DEFAULT_X_AMPLITUDE;
		param->zoom = 1;
		param->o_re = 0;
		param->o_im = 0;
		param->num_max_iter = DEFAULT_NUM_MAX_ITER;
		fra_draw(param);
		fra_print_stat(param);
		return (0);
	}
	if (key == 53)
	{
		fra_free_param(&param, 0, 11112);
		exit(0);
	}
	key_press2(key, param);
	return (0);
}
