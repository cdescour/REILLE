/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:21:30 by lreille           #+#    #+#             */
/*   Updated: 2023/03/12 00:28:12 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	ft_isdigit_and_symbol(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '.'))
		return (1);
	return (0);
}

int	ft_dot_pos(char *info)
{
	int	i;

	i = 0;
	while (info[i])
	{
		if (info[i] == '.')
			return (i);
		i++;
	}
	return (0);
}

int	ft_contains_wrong_symbols(char *info)
{
	int	i;

	i = 0;
	while (info[i])
	{
		if (ft_isdigit_and_symbol(info[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int ft_vector_nb_check(int v1, int v2, int v3)
{
	if (v1 == 0 && v2 == 0 && v3 == 0)
		ft_error(E1018);
	return (1);
}
