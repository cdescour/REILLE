/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:09:49 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 17:47:23 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	save_plan(char **info1, char **info2, char **info3, t_item *item)
{
	t_plan	*tmp;

	if (item->plan == NULL)
		item->plan = init_plan(info1, info2, info3);
	else
	{
		tmp = item->plan;
		item->plan = init_plan(info1, info2, info3);
		item->plan->next = tmp;
	}
	item->nb_plan += 1;
}

t_plan	*init_plan(char **info1, char **info2, char **info3)
{
	t_plan *plan;
		
	plan = malloc(sizeof(t_plan));
	plan->pos = save_pos(info1);
	plan->dir = save_dir(info2);
	plan->color = save_color(info3);
	plan->next = NULL;

	return (plan);
}
