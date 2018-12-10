/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_print_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:10:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/10 12:01:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static	void	print_coord(t_fra_param *param, int precision)
{
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 25,
		param->stat_colour, "x:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 25,
		param->stat_colour,
		ft_ldtoa(fra_pix_to_re(param, param->pointer->px), precision));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 45,
		param->stat_colour, "y:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 45,
		param->stat_colour,
		ft_ldtoa(fra_pix_to_im(param, param->pointer->py), precision));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 85,
		param->stat_colour, "center x:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 100, 85,
		param->stat_colour,
		ft_ldtoa(param->c_re, precision));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 105,
		param->stat_colour, "center y:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 100, 105,
		param->stat_colour,
		ft_ldtoa(param->c_im, precision));
}

void			fra_print_stat(t_fra_param *param)
{
	int precision;
	int pow;

	precision = 6;
	pow = 1;
	while (param->zoom / pow > 1)
	{
		pow *= 10;
		precision++;
	}
	mlx_clear_window(param->mlx_ptr, param->win_stat_ptr);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 5,
		param->stat_colour, "Fractal type :");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 150, 5,
		param->stat_colour, ft_itoa(param->type));
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 65,
		param->stat_colour, "zoom:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 70, 65,
		param->stat_colour, ft_itoa(param->zoom));
	print_coord(param, precision);
}
