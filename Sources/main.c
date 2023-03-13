/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:56:14 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/12 11:44:43 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_item	obj;


	check_arg(&arg, argc, argv);
	parse_arg(&arg, &obj);
		
	return (0);
}
