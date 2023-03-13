/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:50:23 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 15:31:08 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

void save_cam(char **info1, char **info2, char *info3, t_item *item)
{
	item->cam = malloc(sizeof(t_cam));
	item->cam->pos = save_pos(info1);
	item->cam->dir = save_dir(info2);
	item->cam->fov = ft_atoi(info3);
	item->nb_cam += 1;
}

t_pos *save_pos(char **info1)
{
	t_pos	*pos;
	char	**temp1;
	char	**temp2;
	char	**temp3;

	temp1 = ft_split(info1[0], '.');
	temp2 = ft_split(info1[1], '.');
	temp3 = ft_split(info1[2], '.');
	pos = malloc(sizeof(t_pos));
	pos->x = ft_atoi(temp1[0]) * 1000;
   	if (temp1[1])
   		pos->x += ft_atoi_size(temp1[1], 3);
	pos->y = ft_atoi(temp2[0]) * 1000;
	if (temp2[1])
		pos->y += ft_atoi_size(temp2[1], 3);
	pos->z = ft_atoi(temp3[0]) * 1000;
	if (temp3[1])
		pos->z += ft_atoi_size(temp3[1], 3);
	free_tab (temp1);
	free_tab (temp2);
	free_tab (temp3);
	return (pos);
}

t_dir *save_dir(char **info2)
{
	t_dir	*dir;
	char	**temp1;
	char	**temp2;
	char	**temp3;

	temp1 = ft_split(info2[0], '.');
	temp2 = ft_split(info2[1], '.');
	temp3 = ft_split(info2[2], '.');
	dir = malloc(sizeof(t_dir));
	dir->x = ft_atoi(temp1[0]) * 1000;
	if (temp1[1])
		dir->x += ft_atoi_size(temp1[1], 3);
	dir->y = ft_atoi(temp2[0]) * 1000;
	if (temp2[1])
		dir->y += ft_atoi_size(temp2[1], 3);
	dir->z = ft_atoi(temp3[0]) * 1000;
	if (temp3[1])
		dir->z += ft_atoi_size(temp3[1], 3);
	free_tab (temp1);
	free_tab (temp2);
	free_tab (temp3);
	return (dir);
}
