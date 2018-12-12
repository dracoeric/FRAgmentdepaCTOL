/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_make_grad_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:40:20 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 11:43:54 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "libft.h"

t_colour	*fra_make_grad_1(void)
{
	t_colour *grad;

	if (!(grad = (t_colour *)malloc(sizeof(t_colour) * 16)))
		return (ft_msg_ptr(2, "Malloc error for grad.\n", 0));
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
