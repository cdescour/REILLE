/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:37:56 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 22:42:47 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_check_obj(char **tab, t_item *item)
{
	if (!tab[0])
	{
		free(tab);
		return (true);
	}
	else if (!ft_strcmp("C", tab[0]))
		return (ft_check_C_content(tab, item));
	else if (!ft_strcmp("L", tab[0]))
		return (ft_check_L_content(tab, item));
	else if (!ft_strcmp("A", tab[0]))
		return (ft_check_A_content(tab, item));
	else if (!ft_strcmp("sp", tab[0]))
		return (ft_check_sp_content(tab, item));
	else if (!ft_strcmp("pl", tab[0]))
		return (ft_check_pl_content(tab, item));
	else if (!ft_strcmp("cy", tab[0]))
		return (ft_check_cyl_content(tab, item));
	return (false);
}
/*
void	ft_input_obj(char **tab, t_item *item)
{
	if (ft_strcmp("A", tab[0]) == 0)
		ft_A_input(tab, item);
}*/
