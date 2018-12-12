/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:37:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 14:20:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static	void	manage_zoom(int button, int x, int y, t_fra_param *para)
{
	if (button == 4 && para->zoom < MAX_ZOOM && para->key_pressed == 0)
	{
		para->o_re += (fra_pix_to_re(para, x) - para->o_re) * para->zoom_incr;
		para->o_im += (fra_pix_to_im(para, y) - para->o_im) * para->zoom_incr;
		para->zoom *= ZOOM_INCR;
		para->qx /= ZOOM_INCR;
		para->qy /= ZOOM_INCR;
	}
	if (button == 5 && para->zoom != 1 && para->key_pressed == 0)
	{
		para->o_re += (fra_pix_to_re(para, x) - para->o_re) * para->zoom_decr;
		para->o_im += (fra_pix_to_im(para, y) - para->o_im) * para->zoom_decr;
		para->zoom /= ZOOM_INCR;
		para->qx *= ZOOM_INCR;
		para->qy *= ZOOM_INCR;
		if (para->zoom <= 1)
		{
			para->qx = (double)DEFAULT_X_AMPLITUDE
				/ (double)IMG_HEIGHT;
			para->qy = (double)DEFAULT_X_AMPLITUDE;
			para->zoom = 1;
			para->o_re = 0;
			para->o_im = 0;
		}
	}
}

static	void	manage_iter(int button, int x, int y, t_fra_param *param)
{
	x = 1;
	y = 1;
	if (button == 4 && param->key_pressed == 1)
	{
		param->num_max_iter += 20;
		fra_draw(param);
	}
	if (button == 5 && param->key_pressed == 1)
	{
		if (param->num_max_iter > DEFAULT_NUM_MAX_ITER)
			param->num_max_iter -= 20;
		else
			param->num_max_iter = DEFAULT_NUM_MAX_ITER;
	}
}

int				fra_mouse_press(int button, int x, int y, void *param)
{
	t_fra_param *para;

	if (button == 4 || button == 5)
	{
		if (param == 0)
			return (0);
		para = (t_fra_param *)param;
		manage_zoom(button, x, y, para);
		manage_iter(button, x, y, para);
		fra_draw(para);
		fra_print_stat(para);
	}
	return (0);
}
