/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:37:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/10 11:58:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static	void	manage_zoom(int button, int x, int y, t_fra_param *para)
{
	if (button == 4 && para->zoom < MAX_ZOOM)
	{
		para->zoom *= 2;
		para->c_re = fra_pix_to_re(para, x);
		para->c_im = fra_pix_to_im(para, y);
		para->qx /= 2;
		para->qy /= 2;
	}
	if (button == 5 && para->zoom != 1)
	{
		para->zoom /= 2;
		para->qx *= 2;
		para->qy *= 2;
		if (para->zoom == 1)
		{
			para->c_re = 0;
			para->c_im = 0;
		}
	}
}

int				fra_mouse_press(int button, int x, int y, void *param)
{
	t_fra_param *para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	ft_printf("Button %d pressed at z = %Lf +i %LF.\n", button,
		fra_pix_to_re(para, x), fra_pix_to_im(para, y));
	manage_zoom(button, x, y, para);
	fra_print_stat(para);
	return (0);
}
