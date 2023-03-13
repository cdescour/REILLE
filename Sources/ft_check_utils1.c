/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:24:34 by lreille           #+#    #+#             */
/*   Updated: 2023/03/12 00:31:38 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
/*
int	ft_count_dot(char *info)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (info[i])
	{
		if (info[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

int	ft_neg_in_check(char *info)
{
	int	i;

	i = 0;
	if (info[0] == '-')
		i = 1;
	while (info[i])
	{
		if (info[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_neg_check(char *info)
{
	int	i;

	i = 0;
	if (ft_neg_in_check(info) == 1)
		return (0);
	if (info[0] == '-')
		return (1);
	return (0);
}

int	ft_int_start(char *info)
{
	int	i;

	i = 0;
	if (ft_neg_check(info) == 1)
		i = 1;
	while (info[i] == '0')
		i++;
	return (i);
}

int	ft_good_after_dot(char *info)
{
	int	i;

	i = ft_strlen(info) - 1;
	if (info[i] == '.')
		return (0);
	return (1);
}*/
