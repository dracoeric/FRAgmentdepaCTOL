/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_init_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:40:48 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 13:04:31 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

int				fra_init_3(t_fra_param *param)
{
	if (!(param->mutex = (t_mutex *)malloc(sizeof(t_mutex))))
		return (fra_free_param(&param, -1, 1112));
	param->mutex->px = 0;
	param->mutex->py = 0;
	param->mutex->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	fra_draw(param);
	return (0);	
}

int				fra_init_2(t_fra_param *param, enum e_fra_type type)
{
	if (!(param->pointer = (t_pixcoord *)malloc(sizeof(t_pixcoord))))
		return (fra_free_param(&param, -1, 12));
	param->pointer->px = 0;
	param->pointer->py = 0;
	param->pointer->pz = 0;
	param->stat_colour = mlx_str_to_colour(WIN_STAT_TEXT_COLOUR);
	param->num_max_iter = DEFAULT_NUM_MAX_ITER;
	param->type = type;
	param->key_pressed = 0;
	param->zoom = 1;
	param->qx = (long double)DEFAULT_X_AMPLITUDE / (long double)IMG_HEIGHT;
	param->qy = (long double)DEFAULT_X_AMPLITUDE;
	param->zoom_incr = (long double)(ZOOM_INCR - 1) / (long double)ZOOM_INCR;
	param->zoom_decr = (long double)(1 - ZOOM_INCR);
	param->o_re = 0;
	param->o_im = 0;
	param->c_re = -0.5;
	param->c_im = 0.5;
	param->cg = &fra_cg_grad;
	if (!(param->grad = fra_make_grad_1()))
		return (fra_free_param(&param, -1, 112));
	fra_init_3(param);
	return (0);
}

t_fra_param		*fra_init_param(enum e_fra_type type)
{
	t_fra_param	*param;

	if (!(param = (t_fra_param *)malloc(sizeof(t_fra_param))))
		return (ft_msg_ptr(2, "Malloc Error for Param.\n", NULL));
	if (!(param->mlx_ptr = mlx_init()))
		return (ft_msg_ptr(2, "Failed to make X-connection.\n", 0));
	if (!(param->win_ptr = mlx_new_window(param->mlx_ptr, IMG_WIDTH,
		IMG_HEIGHT, "Fractol")))
		return (ft_msg_ptr(2, "Failed to create a window.\n", 0));
	if (!(param->win_stat_ptr = mlx_new_window(param->mlx_ptr, WIN_STAT_WIDTH,
		WIN_STAT_HEIGHT, "Parameters")))
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		free(param);
		return (ft_msg_ptr(2, "Failed to create a window.\n", 0));
	}
	if (!(param->img = mlx_img_create(param->mlx_ptr, IMG_WIDTH, IMG_HEIGHT)))
	{
		fra_free_param(&param, -1, 2);
		return (ft_msg_ptr(2, "Malloc Error for img.\n", NULL));
	}
	fra_init_2(param, type);
	return (param);
}
