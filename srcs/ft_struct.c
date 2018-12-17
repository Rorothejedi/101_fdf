/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 18:54:34 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:07:22 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Initialise la variable (struct) ptr.
*/

t_mlx		*ft_struct_init(int fd, int nb_line, int nb_number)
{
	t_mlx	*ptr;

	if (!(ptr = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_error("Error : Echec d'allocation memoire (malloc).");
	ptr->nb_number = nb_number;
	ptr->nb_line = nb_line;
	ptr->arr = ft_parser_extract_number(fd, nb_line, -1);
	ptr->set = ft_struct_param(ptr);
	ptr->pos = ft_struct_pos();
	ptr->color = ft_struct_color();
	return (ptr);
}

/*
** Initialise la structure t_param.
*/

t_param		*ft_struct_param(t_mlx *ptr)
{
	t_param	*temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_param))))
		ft_error("Error : Echec d'allocation memoire (malloc).");
	temp->color_u = "white";
	temp->color_d = "white";
	temp->color = 16777215;
	temp->type = 'i';
	temp->size = 40;
	temp->depth = 0.1;
	temp->sensitivity = 1;
	temp->x_min = 0;
	temp->y_min = 0;
	temp->z_max = ft_calc_z_max(ptr);
	temp->z_min = ft_calc_z_min(ptr);
	return (temp);
}

/*
** Initialise la structure t_pos.
*/

t_pos		*ft_struct_pos(void)
{
	t_pos	*temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_pos))))
		ft_error("Error : Echec d'allocation memoire (malloc).");
	temp->x1 = 0;
	temp->y1 = 0;
	temp->x2 = 0;
	temp->y2 = 0;
	temp->count = 0;
	return (temp);
}

/*
** Initialise la structure t_color.
*/

t_color		*ft_struct_color(void)
{
	t_color	*temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_color))))
		ft_error("Error : Echec d'allocation memoire (malloc).");
	temp->c = 16777215;
	temp->white = "white";
	temp->red = "red";
	temp->green = "green";
	temp->blue = "blue";
	temp->pink = "pink";
	temp->yellow = "yellow";
	temp->cyan = "cyan";
	temp->black = "black";
	return (temp);
}

/*
** Permet de free toutes les structures.
*/

void		ft_struct_free(t_mlx *ptr)
{
	ft_arrdel_i(ptr->arr, ptr->nb_line);
	free(ptr->set);
	free(ptr->pos);
	free(ptr->color);
	ptr->set = NULL;
	ptr->pos = NULL;
	ptr->color = NULL;
	free(ptr);
	ptr = NULL;
}
