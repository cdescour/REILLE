/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:29:15 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 18:13:10 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void	save_sphere(char **info1, char *info2, char **info3, t_item *item)
{
	t_sphere	*tmp;

	if (item->sphere == NULL)
		item->sphere = init_sphere(info1, info2, info3);
	else
	{
		tmp = item->sphere;
		item->sphere = init_sphere(info1, info2, info3);
		item->sphere->next = tmp;
	}
	item->nb_sphere += 1; 
}

t_sphere	*init_sphere(char **info1, char *info2, char **info3)
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->pos = save_pos(info1);
	sphere->diam = save_distance(info2);
	sphere->color = save_color(info3);
	sphere->next = NULL;
	return (sphere);
}

int	save_distance(char *str)
{
	int	i;
	char **tab;

	tab = ft_split(str, '.');
	i = ft_atoi(tab[0]) * 1000;
	if (tab[1] != NULL)
		i += ft_atoi_size(tab[1], 3);
	free_tab(tab);
	return (i);
}
