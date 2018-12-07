/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_pix_to_im.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:52:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 17:07:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double		fra_pix_to_im(t_fra_param *param, t_pixcoord *pix)
{
	long double ima;

	ima = (long double)pix->px * (long double)(DEFAULT_X_AMPLITUDE)
		/ (param->zoom * IMG_HEIGHT);
	return (ima);
}
