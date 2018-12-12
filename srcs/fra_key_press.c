/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 09:23:18 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		fra_key_press(int key, void *arg)
{
	t_fra_param *param;

	param = (t_fra_param *)arg;
	if (key == 256)
		param->key_pressed = 1;
	if (key == 3)
	{
		fra_draw(param);
		fra_print_stat(param);
	}
	if (key == 15)
	{
		param->qx = (long double)DEFAULT_X_AMPLITUDE
			/ (long double)IMG_HEIGHT;
		param->qy = (long double)DEFAULT_X_AMPLITUDE;
		param->zoom = 1;
		param->o_re = 0;
		param->o_im = 0;
		param->num_max_iter = DEFAULT_NUM_MAX_ITER;
		fra_draw(param);
		fra_print_stat(param);
	}
	if (key == 53)
	{
		fra_free_param(&param, 0, 1112);
		exit(0);
	}
	return (0);
}
