/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:01:28 by lreille           #+#    #+#             */
/*   Updated: 2023/03/13 15:41:52 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int    ft_check_A_content(char **tab, t_item *item)
{
	char    *info1;
	char    **info2;
	int		stats;

	stats = true;
	if (ft_dbltablen(tab) != 3)
		ft_error(E1020);
	info1 = tab[1];
	info2 = ft_split(tab[2], ',');
	if (ft_lum_ratio_check(info1) == false)
		stats = false;
	if (ft_check_colors(info2) == false)
		stats = false;
	if (stats == true)
		save_amb(info1, info2, item);
	free(info1);
	free_tab(info2);
	return (stats);
}

int    ft_check_C_content(char **tab, t_item *item)
{
	char    **info1;
	char    **info2;
	char    *info3;
	int		stats;

	stats = true;
	if (ft_dbltablen(tab) != 4)
		return (false);
	info1 = ft_split(tab[1], ',');
	info2 = ft_split(tab[2], ',');
	info3 = tab[3];
	if (ft_coord_check(info1) == false)
		stats = false;
	if (ft_vector_check(info2) == false)
		stats = false;
	if (ft_check_fov(info3) == false)
		stats = false;
	if (item->nb_cam != 0)
		stats = false;
	if (stats == true)
		save_cam(info1, info2, info3, item);
	free_tab(info1);
	free_tab(info2);
	free(info3);
	return (stats);
}

int	ft_check_L_content(char **tab, t_item *item)
{
	char    **info1;
	char    *info2;
	int		stats;

	stats = true;
	if (ft_dbltablen(tab) != 4 && ft_dbltablen(tab) != 3)
		ft_error(E1020);
	info1 = ft_split(tab[1], ',');
	info2 = tab[2];
	if (ft_dbltablen(tab) == 4)
	{
		if (ft_check_L_content_extra(tab) == false)
			stats = false;
	}
	if (ft_coord_check(info1) == false)
		stats = false;
	if (ft_lum_ratio_check(info2) == false)
		stats = false;
	if (item->nb_spot != 0)
		stats = false;
	if (stats == true)
		save_spot(info1, info2, item);
	free_tab(info1);
	free(info2);
	return (stats);
}

int	ft_check_L_content_extra(char **tab)
{
	char	**info3;
	int		stats;

	stats = true;
	info3 = ft_split(tab[3], ',');
	if (ft_check_colors(info3) == false)
		stats = false;
	free_tab (info3);
	return (stats);
}
