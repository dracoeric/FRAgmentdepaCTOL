/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_make_grad_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:40:20 by erli              #+#    #+#             */
/*   Updated: 2018/12/13 14:23:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "libft.h"

static	t_colour	*grad_1(t_colour *grad)
{
	grad[0] = mlx_str_to_colour("0x00421e0f");
	grad[1] = mlx_str_to_colour("0x0019071a");
	grad[2] = mlx_str_to_colour("0x0009012f");
	grad[3] = mlx_str_to_colour("0x00040449");
	grad[4] = mlx_str_to_colour("0x00000764");
	grad[5] = mlx_str_to_colour("0x000c288a");
	grad[6] = mlx_str_to_colour("0x001852b1");
	grad[7] = mlx_str_to_colour("0x00397dd1");
	grad[8] = mlx_str_to_colour("0x0086b5e5");
	grad[9] = mlx_str_to_colour("0x00d3ecf8");
	grad[10] = mlx_str_to_colour("0x00f1e9bf");
	grad[11] = mlx_str_to_colour("0x00f8c95f");
	grad[12] = mlx_str_to_colour("0x00ffaa00");
	grad[13] = mlx_str_to_colour("0x00cc8000");
	grad[14] = mlx_str_to_colour("0x00995700");
	grad[15] = mlx_str_to_colour("0x006a3403");
	return (grad);
}

t_colour			*fra_change_grad(t_colour *grad, int n)
{
	if (n == 0)
		return (grad_1(grad));
	grad[0] = mlx_str_to_colour("0x000f0f0f");
	grad[1] = mlx_str_to_colour("0x001f1f10");
	grad[2] = mlx_str_to_colour("0x002f2f21");
	grad[3] = mlx_str_to_colour("0x003f3f32");
	grad[4] = mlx_str_to_colour("0x004f4f43");
	grad[5] = mlx_str_to_colour("0x005f5f54");
	grad[6] = mlx_str_to_colour("0x006f6f65");
	grad[7] = mlx_str_to_colour("0x007f7f76");
	grad[8] = mlx_str_to_colour("0x008f8f87");
	grad[9] = mlx_str_to_colour("0x009f9f98");
	grad[10] = mlx_str_to_colour("0x00afafa9");
	grad[11] = mlx_str_to_colour("0x00bfbfba");
	grad[12] = mlx_str_to_colour("0x00cfcfcb");
	grad[13] = mlx_str_to_colour("0x00dfdfdc");
	grad[14] = mlx_str_to_colour("0x00efefed");
	grad[15] = mlx_str_to_colour("0x00fffffe");
	return (grad);
}
