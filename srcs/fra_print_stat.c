/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_print_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:10:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 17:23:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	fra_print_stat(t_fra_param *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_stat_ptr);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 5,
		param->stat_colour, "Fractal type :");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 150, 5,
		param->stat_colour, ft_itoa(param->type));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 25,
		param->stat_colour, "x:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 25,
		param->stat_colour, ft_itoa(param->pointer->px));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 45,
		param->stat_colour, "y:");
//	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 45,
//		param->stat_colour, ft_ldtoa(fra_pix_to_im(param, param->pointer)));	
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 65,
		param->stat_colour, "zoom:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 700, 65,
		param->stat_colour, ft_itoa(param->zoom));
}
