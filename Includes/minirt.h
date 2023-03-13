/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/13 22:43:35 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <mlx.h>

# include "../Libft/libft.h"


# define true 1
# define false 0

//setings
# define IMG_X 1920
# define IMG_Y 1080

//E1->argcheck an objects
# define E1001 "Error\nNot enough arguments\n"
# define E1002 "Error\nToo many arguments\n"
# define E1003 "Error\nFile name not defined\n"
# define E1004 "Error\nFile can not be found\n"
# define E1005 "Error\nWrong place for negative sign\n"
# define E1006 "Error\nHas more than one dot\n"
# define E1007 "Error\nContains invalid symbols\n"
# define E1008 "Error\nCan't have nothing after dot :(\n"
# define E1009 "Error\nWrong orientation vector range on x\n"
# define E1010 "Error\nWrong orientation vector range on y\n"
# define E1011 "Error\nWrong orientation vector ranke on z\n"
# define E1012 "Error\nLuminosity ratio out of range\n"
# define E1013 "Error\nFOV out of range\n"
# define E1014 "Error\nCoordinates of 'x' out of the zone!\n"
# define E1015 "Error\nCoordinates of 'y' out of the zone!\n"
# define E1016 "Error\nCoordinates of 'z' out of the zone!\n"
# define E1017 "Error\nToo many elements!\n"
# define E1018 "Error\nCan't have them all at 0...\n"
# define E1019 "Error\nInvalid colors input\n"
# define E1020 "Error\nWrong amount of elements\n"

typedef struct s_sphere t_sphere;
typedef struct s_plan t_plan;
typedef struct s_cyl t_cyl;

typedef struct s_pos
{
	int	x;
	int	y;
	int	z;
}	t_pos;

typedef struct s_dir
{
	int x;
	int y;
	int z;
}	t_dir;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_cam
{
    t_pos   *pos;
    t_dir   *dir;
    int     fov;
}   t_cam;

typedef struct s_amb
{
    int     intensity;
    t_color *color;
}   t_amb;

typedef struct s_spot
{
    t_pos   *pos;
    int     intensity;
}	t_spot;

typedef struct s_sphere
{
    t_pos   *pos;
    int     diam;
    t_color *color;
	t_sphere *next;
}   t_sphere;

typedef struct s_plan
{
    t_pos   *pos;
    t_dir   *dir;
    t_color *color;
	t_plan	*next;
} t_plan;

typedef struct s_cyl
{
    t_pos   *pos;
    t_dir   *dir;
    int     d;
    int     height;
    t_color *color;
	t_cyl	*next;
}   t_cyl;

typedef struct s_arg
{
    char    *name_file;
    int     fd_file;

}       t_arg;

typedef struct s_item
{
	int			nb_equation;
	int			nb_cam;
	int			nb_amb;
	int			nb_spot;
	int			nb_sphere;
	int			nb_plan;
	int			nb_cyl;
	t_cam		*cam;
	t_amb		*amb;
	t_spot		*spot;
	t_sphere	*sphere;
	t_plan		*plan;
	t_cyl		*cyl;
}   t_item;

typedef struct s_tcyl
{
	char	**i1;
    char	**i2;
    char	*i3;
    char    *i4;
    char	**i5;
	int		stats;
}	t_tcyl;

//main.c
int		main(int argc, char **argv);

//amb.c
void	save_amb(char *info1, char **info2, t_item *item);
t_color	*save_color(char **colors);

//cam.c
void	save_cam(char **info1, char **info2, char *info3, t_item* item);
t_pos	*save_pos(char **info1);
t_dir	*save_dir(char **info2);

//spot.c
void	save_spot(char **info1, char *info2, t_item *item);

//sphere.c
void	save_sphere(char **info1, char *info2, char **info3, t_item *item);
t_sphere	*init_sphere(char **info1, char *info2, char **info3);
int		save_distance(char *str);

//plan.c
void	save_plan(char **info1, char **info2, char **info3, t_item *item);
t_plan	*init_plan(char **info1, char **info2,char **info3);

//cylinder.c
void save_cylinder(t_tcyl l,t_item *item);
t_cyl	*init_cylinder(t_tcyl l);
//check_arg.c
void	 check_arg(t_arg *arg, int argc, char **argv);

//check_obj.c
int		ft_strcmp(char *s1, char *s2);
int		ft_check_obj(char **tab, t_item *item);
void	ft_input_obj(char **tab, t_item *item);

//error.c
void	ft_error(char *str);

//free.c
void	free_tab(char **tab);

//ft_check_data_1.c
int	ft_coord_check(char **info);
int	ft_lum_ratio_check(char *info);
int	ft_check_fov(char *info);
int	ft_check_colors(char **info);
int	ft_vector_check(char **info);

//ft_check_data_2.c
void	ft_check_ratio(char **info);
int		ft_splitted_char_check(char **info);
int		ft_char_check(char *info);
int		ft_check_float(char *info);

//ft_check_utils1.c
int		ft_count_dot(char *info);
int		ft_neg_in_check(char *info);
int		ft_neg_check(char *info);
int		ft_int_start(char *info);
int		ft_good_after_dot(char *info);

//ft_data_utils1.c
int	ft_count_dot(char *info);
int	ft_neg_in_check(char *info);
int	ft_neg_check(char *info);
int	ft_int_start(char *info);
int	ft_good_after_dot(char *info);

//ft_data_utils2.c
int		ft_isdigit_and_and_symbol(char c);
int		ft_dot_pos(char *info);
int		ft_contains_wrong_symbols(char *info);
int		ft_vector_nb_check(int v1, int v2, int v3);//see ft_error

//ft_elem_cap_check.c
int		ft_check_A_content(char **tab, t_item *item);
int		ft_check_C_content(char **tab, t_item *item);
int		ft_check_L_content(char **tab, t_item *item);
int		ft_check_L_content_extra(char **tab);

//ft_elem_min_check.c
int		ft_check_pl_content(char **tab, t_item *item);
int		ft_check_sp_content(char **tab, t_item *item);
int		ft_check_cyl_content(char **tab, t_item *item);
//int		ft_check_cy_content_extra(char **tab);//, t_item *item);

//ft_elem_cap_input.c
void	ft_A_input(char **tab, t_item *item);

//ft_input_conversion.c
int		ft_convert_float(char *info);
int		ft_is_input(char *info);
int		ft_is_nofloat(char *info);

//ft_utils1.c
size_t	ft_dbltablen(char **tab);

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
//char	*ft_strjoin(char *s1, char *s2);

//parse_file.c
char	*get_line(t_arg *arg);
void	parse_arg(t_arg *arg, t_item *item);
void	init_item(t_item *item);
void	write_status(t_item*item);

#endif
