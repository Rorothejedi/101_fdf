/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cabinet.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 21:02:19 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:19:11 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Toutes les fonctions de ce fichier permettent de gerer la projection
** cabinet qui est un des deux type de projection oblique.
*/

double	ft_cabinet_x(int x, int z)
{
	double x_obl;

	x_obl = x + (1 / 2) * z * cos(180 * M_PI / 180);
	return (x_obl);
}

double	ft_cabinet_y(int y, int z)
{
	double y_obl;

	y_obl = y + (1 / 2) * z * sin(180 * M_PI / 180);
	return (y_obl);
}

t_mlx	*ft_cabinet_width(t_mlx *ptr, int z1, int x, int y)
{
	int z2;
	int w;
	int h;

	w = W_WIDTH * 35 / 100 - ptr->set->x_min;
	h = W_HEIGHT * 20 / 100 - ptr->set->y_min;
	ptr->pos->x1 = (ft_cabinet_x(x, y) * ptr->set->size) + w;
	ptr->pos->y1 = ((ft_cabinet_y(y, z1) - z1) * ptr->set->size) + h;
	z2 = ptr->arr[y - ptr->set->y_min][x + 1 - ptr->set->x_min]
		* ptr->set->depth;
	ptr->pos->x2 = (ft_cabinet_x(x + 1, y) * ptr->set->size) + w;
	ptr->pos->y2 = ((ft_cabinet_y(y, z2) - z2) * ptr->set->size) + h;
	return (ptr);
}

t_mlx	*ft_cabinet_height(t_mlx *ptr, int z1, int x, int y)
{
	int z2;
	int w;
	int h;

	w = W_WIDTH * 35 / 100 - ptr->set->x_min;
	h = W_HEIGHT * 20 / 100 - ptr->set->y_min;
	ptr->pos->x1 = (ft_cabinet_x(x, y) * ptr->set->size) + w;
	ptr->pos->y1 = ((ft_cabinet_y(y, z1) - z1) * ptr->set->size) + h;
	z2 = ptr->arr[y + 1 - ptr->set->y_min][x - ptr->set->x_min]
		* ptr->set->depth;
	ptr->pos->x2 = (ft_cabinet_x(x, y + 1) * ptr->set->size) + w;
	ptr->pos->y2 = ((ft_cabinet_y(y + 1, z2) - z2) * ptr->set->size) + h;
	return (ptr);
}

void	ft_cabinet_trace(t_mlx *ptr, int x, int y)
{
	int z1;

	z1 = ptr->arr[y - ptr->set->y_min][x - ptr->set->x_min] * ptr->set->depth;
	if (x < ptr->nb_number + ptr->set->x_min - 1)
	{
		ptr = ft_cabinet_width(ptr, z1, x, y);
		if (ft_calc_opt_display(ptr) == 1)
			ft_line(ptr);
	}
	if (y < ptr->nb_line + ptr->set->y_min - 1)
	{
		ptr = ft_cabinet_height(ptr, z1, x, y);
		if (ft_calc_opt_display(ptr) == 1)
			ft_line(ptr);
	}
}
