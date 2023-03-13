/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:27:07 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/09 23:55:42 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	ft_coord_check(char **info)
{
	int	x;
	int	y;
	int	z;

	x = ft_is_input(info[0]);
	y = ft_is_input(info[1]);
	z = ft_is_input(info[2]);
	if (ft_splitted_char_check(info) == 0)
		ft_error(E1007);
	if (x <= INT_MIN || x >= INT_MAX)
        ft_error(E1014);
	if (y <= INT_MIN || y >= INT_MAX)
        ft_error(E1015);
	if (z <= INT_MIN || z >= INT_MAX)
        ft_error(E1016);
	return (1);
}

int	ft_lum_ratio_check(char *info)
{
	int	ratio;

	ratio = ft_is_input(info);
	if (ft_char_check(info) != 1)
		ft_error(E1007);
	if (ratio < 0 || ratio > 1000)
        ft_error(E1012);
	return (1);
}

int	ft_check_fov(char *info)
{
	int	fov;

	fov = ft_is_input(info);
	if (ft_char_check(info) == 0)
		ft_error (E1007);
	if (fov < 0 || fov > 180000)
        ft_error(E1013);
	return (1);
}

int	ft_check_colors(char **info)
{
    int r;
    int g;
    int b;

    r = ft_atoi(info[0]);
    g = ft_atoi(info[1]);
    b = ft_atoi(info[2]);
	if (ft_splitted_char_check(info) == 0)
		ft_error(E1007);
    if (ft_dbltablen(info) != 3)
        ft_error(E1017);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        ft_error(E1019);
    return (1);
}

int	ft_vector_check(char **info)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = ft_is_input(info[0]);
	v2 = ft_is_input(info[1]);
	v3 = ft_is_input(info[2]);
	if (ft_splitted_char_check(info) == 0)
		ft_error(E1007);
	if (ft_vector_nb_check(v1, v2, v3) == 0)
		ft_error(E1018);
	if (v1 < -1000 || v1 > 1000)
		ft_error(E1009);
	else if (v2 < -1000 || v2 > 1000)
        ft_error(E1010);
	else if (v3 < -1000 || v3 > 1000)
		ft_error(E1011);
	return (1);
}
