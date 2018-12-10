/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_cg_bw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:08:15 by erli              #+#    #+#             */
/*   Updated: 2018/12/10 15:23:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colour	fra_cg_bw(t_fra_param *param, int n)
{
	t_colour colour;

	if (n > param->num_max_iter)
		colour = 0;
	else
		colour = 16777215;
	return (colour);
}
