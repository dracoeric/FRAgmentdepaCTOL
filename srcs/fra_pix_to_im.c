/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_pix_to_im.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:52:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 09:35:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

long double		fra_pix_to_im(t_fra_param *param, int py)
{
	long double ima;

	ima = ((long double)(py * 2) / (long double)IMG_HEIGHT - 1) * param->qy
		+ param->o_im;
	return (ima);
}
