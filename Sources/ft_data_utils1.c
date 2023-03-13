/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:18:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/09 23:55:37 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

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
}
