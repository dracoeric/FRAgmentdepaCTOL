/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_print_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:10:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:44:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

static	void	print_thread_perf(t_fra_param *param, int pre)
{
	char	*str;

	str = ft_dtoa(param->count, pre);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 245,
		param->stat_colour, "count");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 100, 245,
		param->stat_colour, str);
	free(str);
}

static	void	print_coord2(t_fra_param *param, int pre)
{
	char *str;

	str = ft_ldtoa(param->c_im, pre);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 105,
		param->stat_colour, "center y:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 100, 105,
		param->stat_colour, str);
	free(str);
	str = ft_itoa(param->num_max_iter);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 125,
		param->stat_colour, "n iteration:");
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 130, 125,
		param->stat_colour, str);
	free(str);
	print_thread_perf(param, 2);
}

static	void	print_coord(t_fra_param *param, int precision)
{
	char *str;

	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 25,
		param->stat_colour, "x:");
	str = ft_ldtoa(fra_pix_to_re(param, param->pointer->px), precision);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 25,
		param->stat_colour, str);
	free(str);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 45,
		param->stat_colour, "y:");
	str = ft_ldtoa(fra_pix_to_im(param, param->pointer->py), precision);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 40, 45,
		param->stat_colour, str);
	free(str);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 85,
		param->stat_colour, "center x:");
	str = ft_ldtoa(param->c_re, precision);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 100, 85,
		param->stat_colour, str);
	free(str);
	print_coord2(param, precision);
}

void			fra_print_stat(t_fra_param *param)
{
	int		precision;
	int		pow;
	char	*str;

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
	str = ft_itoa(param->type);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 150, 5,
		param->stat_colour, str);
	free(str);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 5, 65,
		param->stat_colour, "zoom:");
	str = ft_ldtoa(param->zoom, 5);
	mlx_string_put(param->mlx_ptr, param->win_stat_ptr, 70, 65,
		param->stat_colour, str);
	free(str);
	print_coord(param, precision);
}
