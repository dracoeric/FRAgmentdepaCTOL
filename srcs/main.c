/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:54:31 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 17:16:43 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

int			main(int argc, char **argv)
{
	t_fra_param *param;

	if (argc != 2)
		ft_msg_int(0, "Missing argument\nUse 'Julia' or 'Mandelbrot'\n", 0);
	else if (fra_type(argv[1]) >= 0)
	{
		if (!(param = fra_init_param(fra_type(argv[1]))))
			return (ft_msg_int(2, "Memory allocation error.\n", 0));
		fra_print_stat(param);
		mlx_hook(param->win_ptr, 2, (1L << 0), &fra_key_press, param);
		mlx_hook(param->win_ptr, 3, (1L << 1), &fra_key_release, param);
		mlx_hook(param->win_ptr, 6, (1L << 5), &fra_mouse_move, param);
		mlx_hook(param->win_ptr, 4, (1L << 2), &fra_mouse_press, param);
		mlx_hook(param->win_ptr, 17, (1L << 17), &fra_close, param);
		mlx_loop(param->mlx_ptr);
	}
}
