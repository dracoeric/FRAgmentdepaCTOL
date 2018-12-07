/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mouse_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:37:25 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 15:45:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		fra_mouse_press(int button, int x, int y, void *param)
{
	t_fra_param *para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	ft_printf("Button %d pressed at (%d, %d).\n", button, x, y);
	return (0);
}
