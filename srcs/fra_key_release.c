/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:50:03 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 13:12:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fra_key_release(int key, void *param)
{
	t_fra_param *para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	if (key == 256)
		para->key_pressed = 0;
	return (0);
}
