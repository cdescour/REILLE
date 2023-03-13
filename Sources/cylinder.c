/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:35 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 22:44:33 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void save_cylinder(t_tcyl l,t_item *item)
{
	t_cyl	*tmp;

	write(1,"4",1);
	if (item->cyl == NULL)
		item->cyl = init_cylinder(l);
	else
	{
		tmp = item->cyl;
		item->cyl = init_cylinder(l);
		item->cyl->next = tmp;
	}
	item->nb_cyl += 1;
}

t_cyl	*init_cylinder(t_tcyl l)
{
	t_cyl *cyl;

	cyl = malloc(sizeof(t_cyl));
	cyl->pos = save_pos(l.i1);
	cyl->dir = save_dir(l.i2);
	cyl->d =  save_distance(l.i3);
	cyl->height =  save_distance(l.i4);
	cyl->color = save_color(l.i5);
	cyl->next = NULL;

	return (cyl);
}
