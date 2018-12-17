/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_pix_to_im.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:52:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/17 16:16:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		fra_pix_to_im(t_fra_param *param, int py)
{
	double ima;

	if (param == 0)
		return (0);
	ima = ((double)(py * 2) / (double)IMG_HEIGHT - 1) * param->qy
		+ param->o_im;
	return (ima);
}
