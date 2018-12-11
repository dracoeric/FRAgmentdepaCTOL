/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_cg_grad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:09:38 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 11:41:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colour			fra_cg_grad(t_fra_param *param, int n)
{
	if (n > param->num_max_iter)
		return (0);
	return (param->grad[n % 16]);
}
