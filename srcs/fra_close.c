/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:50:30 by erli              #+#    #+#             */
/*   Updated: 2018/12/14 10:31:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	fra_close(void *param)
{
	t_fra_param	*para;

	if (param == 0)
		return (0);
	para = (t_fra_param *)param;
	fra_free_param(&para, 0, 11112);
	exit(0);
	return (0);
}
