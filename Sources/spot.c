/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:29:37 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 15:42:57 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void save_spot(char **info1, char *info2, t_item *item)
{
	item->spot = malloc(sizeof(t_spot));
	item->spot->pos = save_pos(info1);
	item->spot->intensity = ft_atoi(info2);
	item->nb_spot += 1;
}
