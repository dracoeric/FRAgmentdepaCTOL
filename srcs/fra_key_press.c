/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/07 16:28:40 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		fra_key_press(int key, void *param)
{
	t_fra_param *para;

	para = (t_fra_param *)param;
	if (key == 53)
	{
		fra_free_param(&para, 0, 112);
		exit(0);
	}
	return (0);
}
