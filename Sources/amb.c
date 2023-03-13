/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 15:01:58 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void save_amb(char *info1, char **info2, t_item *item)
{
	item->amb = malloc(sizeof(t_cam));
	item->amb->intensity = ft_atoi(info1);
	item->amb->color = save_color(info2);
	item->nb_amb += 1;
}

t_color *save_color(char **colors)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);

	return (color);
}
