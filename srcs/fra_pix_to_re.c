/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_pix_to_re.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:52:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/17 16:16:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			fra_pix_to_re(t_fra_param *param, int px)
{
	double	real;

	if (param == 0)
		return (0);
	real = (double)((px * 2) - IMG_WIDTH) * param->qx
		+ param->o_re;
	return (real);
}
