/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mouse_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:31:17 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 09:27:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fra_mouse_move(int x, int y, void *param)
{
	t_fra_param *para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	para->pointer->px = x;
	para->pointer->py = y;
	if (para->type == JULIA && para->key_pressed2 == 1 && para->zoom == 1)
	{
		if (x > 2 || x < -2)
			para->c_re = fra_pix_to_re(param, x);
		if (y > 2 || y < -2)
			para->c_im = fra_pix_to_im(param, y);
		fra_draw(para);
	}
	fra_print_stat(para);
	return (0);
}
