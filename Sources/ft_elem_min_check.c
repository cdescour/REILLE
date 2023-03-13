/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:50:18 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 22:39:40 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int    ft_check_pl_content(char **tab, t_item *item)
{
	char	**info1;
	char	**info2;
	char	**info3;
	int		stats;

	stats = true;
    if (ft_dbltablen(tab) != 4)
    	ft_error(E1020);
	info1 = ft_split(tab[1], ',');
	info2 = ft_split(tab[2], ',');
	info3 = ft_split(tab[3], ',');
   	if (ft_coord_check(info1) == false)
		stats = false;
	if (ft_vector_check(info2) == false)
		stats = false;
	if (ft_check_colors(info3) == false)
		stats = false;
	save_plan(info1, info2, info3, item);
	free_tab(info1);
	free_tab(info2);
	free_tab(info3);
	return (stats);
}

int    ft_check_sp_content(char **tab, t_item *item)
{
   	char    **info1;
   	char    *info2;
    char    **info3;
	int	stats;

	stats = true;
    if (ft_dbltablen(tab) != 4)
    	ft_error(E1020);
	info1 = ft_split(tab[1], ',');
	info2 = tab[2];
	info3 = ft_split(tab[3], ',');
	if (ft_coord_check(info1) == false)
		stats = false;
	if (ft_check_float(info2) == false)
		stats = false;
	if (ft_check_colors(info3) == false)
		stats = false;
	save_sphere(info1, info2, info3, item);
	free_tab(info1);
	free(info2);
	free_tab(info3);
	return (stats);
}

int ft_check_cyl_content(char **tab, t_item *item)
{
	t_tcyl	l;

	l.stats = true;
	if (ft_dbltablen(tab) != 6)
		ft_error(E1020);
	l.i1 = ft_split(tab[1], ',');
	l.i2 = ft_split(tab[2], ',');
	l.i3 = tab[3];
	l.i4 = tab[4];
	l.i5 = ft_split(tab[5], ',');
	if (!ft_vector_check(l.i2) || !ft_check_colors(l.i5))
		l.stats = false;
	if (!ft_check_float(l.i3) || !ft_check_float(l.i4) || !ft_coord_check(l.i1))
		l.stats = false;
	save_cylinder(l, item);
	free_tab(l.i1);
	free_tab(l.i2);
	free(l.i3);
	free(l.i4);
	free_tab(l.i5);
	return (l.stats);
}
/*
int    ft_check_cy_content(char **tab)//, t_item *item)
{
   	char    **info1;
    char    **info2;
	int		stats;

	stats = true;
    if (ft_dbltablen(tab) != 6)
    	ft_error(E1020);
    info1 = ft_split(tab[1], ',');
    info2 = ft_split(tab[2], ',');
 	if (ft_coord_check(info1) == false)
		stats = false;
	if (ft_vector_check(info2) == false)
		stats = false;
	//save_cylinder_1(info1, info2, item);
	if (ft_check_cy_content_extra(tab) == false)
		stats = false;
	free_tab(info1);
	free_tab(info2);
    return (stats);
}

int		ft_check_cy_content_extra(char **tab)// t_item *item)
{
	char	*info3;
	char	*info4;
	char	**info5;
	int		stats;

	stats = true;
	info3 = tab[3];
	info4 = tab[4];
	info5 = ft_split(tab[5], ',');
	if (ft_check_float(info3) == false)
		stats = false;
	if (ft_check_float(info4) == false)
		stats = false;
	if (ft_check_colors(info5) == false)
		stats = false;
	//save_cylinder_2(info3, info4, info5, item);
	free(info3);
	free(info4);
	free_tab(info5);
	return (stats);
}*/
