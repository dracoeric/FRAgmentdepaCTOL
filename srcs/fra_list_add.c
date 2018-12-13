/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra_list_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:37:17 by erli              #+#    #+#             */
/*   Updated: 2018/12/12 17:51:48 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		fra_list_add(t_fra_list **list, t_pixcoord *pix)
{
	t_fra_list *elem;

	if (list == NULL || pix == NULL)
		return ;
	if (!(elem = (t_fra_list *)malloc(sizeof(t_fra_list))))
		return ;
	elem->pix = pix;
	elem->next = NULL;
	if (*list == NULL)
		*list = elem;
	else
	{
		elem->next = *list;
		*list = elem;
	}
}
