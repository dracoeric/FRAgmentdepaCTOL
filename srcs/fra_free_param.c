/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_free_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:59:21 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 09:15:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <stdlib.h>

int		fra_free_param(t_fra_param **param, int cas, int setting)
{
	if (param == 0 || *param == 0)
		return (0);
	if (setting / 10 == 1)
	{
		mlx_destroy_image((*param)->mlx_ptr, (*param)->img->ptr);
		free((*param)->img);
	}
	if (setting % 10 >= 1)
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_ptr);
	if (setting % 10 == 2)
		mlx_destroy_window((*param)->mlx_ptr, (*param)->win_stat_ptr);
	if (setting / 100 == 1)
		free((*param)->pointer);
	if (setting / 1000 == 1)
		free((*param)->grad);
	if (setting / 10000 == 1)
		free((*param)->thread_time);
	free(*param);
	if (cas == -1)
		return (ft_msg_int(2, "Data freeing cause by malloc error.\n",
			-1));
	else
		return (ft_msg_int(1, "Data freeing.\n", 0));
}
