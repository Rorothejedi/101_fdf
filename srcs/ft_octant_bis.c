/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_octant_bis.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 18:04:37 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:16:26 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Fonctions d'affichage des quatres derniers octants.
*/

void	ft_octant_fifth(t_mlx *ptr, int dx, int dy)
{
	int e;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (1)
	{
		ft_graphic_pixel(ptr);
		if ((ptr->pos->x1 = ptr->pos->x1 - 1) == ptr->pos->x2)
			break ;
		if ((e = e + dy) >= 0)
		{
			ptr->pos->y1 = ptr->pos->y1 + 1;
			e = e + dx;
		}
	}
}

void	ft_octant_sixth(t_mlx *ptr, int dx, int dy)
{
	int e;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (1)
	{
		ft_graphic_pixel(ptr);
		if ((ptr->pos->y1 = ptr->pos->y1 + 1) == ptr->pos->y2)
			break ;
		if ((e = e + dx) <= 0)
		{
			ptr->pos->x1 = ptr->pos->x1 - 1;
			e = e + dy;
		}
	}
}

void	ft_octant_seventh(t_mlx *ptr, int dx, int dy)
{
	int e;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (1)
	{
		ft_graphic_pixel(ptr);
		if ((ptr->pos->x1 = ptr->pos->x1 - 1) == ptr->pos->x2)
			break ;
		if ((e = e - dy) >= 0)
		{
			ptr->pos->y1 = ptr->pos->y1 - 1;
			e = e + dx;
		}
	}
}

void	ft_octant_eighth(t_mlx *ptr, int dx, int dy)
{
	int e;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (1)
	{
		ft_graphic_pixel(ptr);
		if ((ptr->pos->y1 = ptr->pos->y1 - 1) == ptr->pos->y2)
			break ;
		if ((e = e - dx) >= 0)
		{
			ptr->pos->x1 = ptr->pos->x1 - 1;
			e = e + dy;
		}
	}
}
