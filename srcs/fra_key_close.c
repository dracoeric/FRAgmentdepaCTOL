/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:44:00 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 10:32:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		fra_key_close(int key, void *arg)
{
	t_fra_param *param;

	if (param == 0)
		return (0);
	param = (t_fra_param *)arg;
	if (key == 53)
	{
		fra_free_param(&param, 0, 11112);
		exit(0);
	}
	return (0);
}
