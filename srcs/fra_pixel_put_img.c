/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:27:50 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 09:11:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"

void	fra_pixel_put_img(t_img *img, int x, int y, t_colour colour)
{
	int			i;
	t_colour	*int_ptr;

	i = x * (img->bypp) + y * img->size_line;
	int_ptr = (t_colour *)((img->str) + i);
	int_ptr[0] = colour;
}
