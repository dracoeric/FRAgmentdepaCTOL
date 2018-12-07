/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_pix_to_re.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:52:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 17:22:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

long double		fra_pix_to_re(t_fra_param *param, t_pixcoord *pix)
{
	long double real;

	real = (long double)pix->py * (long double)(DEFAULT_X_AMPLITUDE)
		/ (param->zoom * IMG_HEIGHT);
	return (real);
}
