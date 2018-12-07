/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_mouse_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:31:17 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 16:32:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int		fra_mouse_move(int x, int y, void *param)
{
	t_fra_param *para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	para->pointer->px = x;
	para->pointer->py = y;
	fra_print_stat(para);
	return (0);
}
