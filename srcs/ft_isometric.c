/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isometric.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:10:58 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:30:59 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Toutes les fonctions de ce fichier permettent de gerer la projection
** isometrique qui est le type de projection par defaut de ce projet.
*/

double	ft_isometric_x(int x, int y)
{
	double x_iso;

	x_iso = (sqrt(2) / 2) * (x - y);
	return (x_iso);
}

double	ft_isometric_y(int x, int y, int z)
{
	double y_iso;

	y_iso = sqrt(2 / 3) * z + (1 / sqrt(6) * (x + y));
	return (y_iso);
}

t_mlx	*ft_isometric_width(t_mlx *ptr, int z1, int x, int y)
{
	int z2;
	int w;
	int h;

	w = W_WIDTH * 35 / 100 - ptr->set->x_min;
	h = W_HEIGHT * 20 / 100 - ptr->set->y_min;
	ptr->pos->x1 = (ft_isometric_x(x, y) * ptr->set->size) + w;
	ptr->pos->y1 = ((ft_isometric_y(x, y, z1) - z1) * ptr->set->size) + h;
	z2 = ptr->arr[y - ptr->set->y_min][x + 1 - ptr->set->x_min]
		* ptr->set->depth;
	ptr->pos->x2 = (ft_isometric_x(x + 1, y) * ptr->set->size) + w;
	ptr->pos->y2 = ((ft_isometric_y(x + 1, y, z2) - z2) * ptr->set->size) + h;
	return (ptr);
}

t_mlx	*ft_isometric_height(t_mlx *ptr, int z1, int x, int y)
{
	int z2;
	int w;
	int h;

	w = W_WIDTH * 35 / 100 - ptr->set->x_min;
	h = W_HEIGHT * 20 / 100 - ptr->set->y_min;
	ptr->pos->x1 = (ft_isometric_x(x, y) * ptr->set->size) + w;
	ptr->pos->y1 = ((ft_isometric_y(x, y, z1) - z1) * ptr->set->size) + h;
	z2 = ptr->arr[y + 1 - ptr->set->y_min][x - ptr->set->x_min]
		* ptr->set->depth;
	ptr->pos->x2 = (ft_isometric_x(x, y + 1) * ptr->set->size) + w;
	ptr->pos->y2 = ((ft_isometric_y(x, y + 1, z2) - z2) * ptr->set->size) + h;
	return (ptr);
}

void	ft_isometric_trace(t_mlx *ptr, int x, int y)
{
	int z1;

	z1 = ptr->arr[y - ptr->set->y_min][x - ptr->set->x_min] * ptr->set->depth;
	if (x < ptr->nb_number + ptr->set->x_min - 1)
	{
		ptr = ft_isometric_width(ptr, z1, x, y);
		if (ft_calc_opt_display(ptr) == 1)
			ft_line(ptr);
	}
	if (y < ptr->nb_line + ptr->set->y_min - 1)
	{
		ptr = ft_isometric_height(ptr, z1, x, y);
		if (ft_calc_opt_display(ptr) == 1)
			ft_line(ptr);
	}
}
