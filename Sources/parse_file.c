/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:10:16 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:41 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"
#include <stdio.h>

char    *get_line(t_arg *arg)
{
        int     i;
		char	*str;
        
        i = 0;
        str = get_next_line(arg->fd_file);
        if (!str)
            return (NULL);
        while (str[i])
        {
            if (str[i] == '\n')
                str[i] = '\0';
			else if (str[i] == '\t')
				str[i] = ' ';
            i++;
        }
        return (str);
}

void	init_item(t_item *item)
{
	item->nb_cam = 0;
	item->nb_amb = 0;
	item->nb_spot = 0;
	item->nb_sphere = 0;
	item->nb_plan = 0;
	item->nb_cyl = 0;
	item->cam = NULL;
	item->amb = NULL;
	item->spot = NULL;
	item->sphere = NULL;
	item->plan = NULL;
	item->cyl = NULL;
}

void	write_status(t_item *item)
{	
	ft_putstr_fd("\nObject list:\n", 1);
	ft_putnbr_fd(item->nb_cam, 1);
	ft_putstr_fd(" camera in the file.\n", 1);
	ft_putnbr_fd(item->nb_amb, 1);
	ft_putstr_fd(" ambiante light in the file.\n", 1);
	ft_putnbr_fd(item->nb_spot, 1);
	ft_putstr_fd(" spot in the file.\n", 1);
	ft_putnbr_fd(item->nb_sphere, 1);
	ft_putstr_fd(" sphere(s) in the file.\n", 1);
	ft_putnbr_fd(item->nb_plan, 1);
	ft_putstr_fd(" plan(s) in the file.\n", 1);
	ft_putnbr_fd(item->nb_cyl, 1);
	ft_putstr_fd(" cylinder(s) in the file.\n", 1);
	item->nb_equation = item->nb_cyl + item->nb_sphere + item->nb_plan;
	item->nb_equation = item->nb_equation * IMG_X * IMG_Y * 2;
	ft_putstr_fd("\nSize of image:\n", 1);
	ft_putnbr_fd(IMG_X, 1);
	ft_putstr_fd("x", 1);
	ft_putnbr_fd(IMG_Y, 1);
	ft_putstr_fd(" pixels.\n", 1);
	ft_putstr_fd("\nTotal number of equations:\n", 1);
	ft_putnbr_fd(item->nb_equation, 1);
	ft_putstr_fd("\n", 1);
}

void parse_arg(t_arg *arg, t_item *item)
{
    char    *str;
    char    **splited;

	init_item(item);
    str = get_line(arg);
    while (str)
    {
        splited = ft_split(str, ' ');
		printf("%s\n", splited[0]);
		ft_check_obj(splited, item);
		//ft_input_obj(splited, item);
		free (str);
       str = get_line(arg);
    }
	write_status(item);
}
