/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_line.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 18:08:27 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:30:15 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Algorithme de Bresenham.
** https://fr.wikipedia.org/wiki/Algorithme_de_tracé_de_segment_de_Bresenham
** Gere l'affichage de ligne entre deux points dans les coordonnes sont connues
*/

void	ft_line_first(t_mlx *ptr, int dx)
{
	int dy;

	if ((dy = ptr->pos->y2 - ptr->pos->y1) != 0)
		if (dy > 0)
		{
			if (dx >= dy)
				ft_octant_first(ptr, dx, dy);
			else
				ft_octant_second(ptr, dx, dy);
		}
		else
		{
			if (dx >= -dy)
				ft_octant_third(ptr, dx, dy);
			else
				ft_octant_fourth(ptr, dx, dy);
		}
	else
		while (1)
		{
			ft_graphic_pixel(ptr);
			if ((ptr->pos->x1 = ptr->pos->x1 + 1) == ptr->pos->x2)
				break ;
		}
}

void	ft_line_second(t_mlx *ptr, int dx)
{
	int dy;

	if ((dy = ptr->pos->y2 - ptr->pos->y1) != 0)
		if (dy > 0)
		{
			if (-dx >= dy)
				ft_octant_fifth(ptr, dx, dy);
			else
				ft_octant_sixth(ptr, dx, dy);
		}
		else
		{
			if (dx <= dy)
				ft_octant_seventh(ptr, dx, dy);
			else
				ft_octant_eighth(ptr, dx, dy);
		}
	else
		while (1)
		{
			ft_graphic_pixel(ptr);
			if ((ptr->pos->x1 = ptr->pos->x1 - 1) == ptr->pos->x2)
				break ;
		}
}

void	ft_line_last(t_mlx *ptr)
{
	int dy;

	if ((dy = ptr->pos->y2 - ptr->pos->y1) != 0)
	{
		if (dy > 0)
			while (1)
			{
				ft_graphic_pixel(ptr);
				if ((ptr->pos->y1 = ptr->pos->y1 + 1) == ptr->pos->y2)
					break ;
			}
		else
			while (1)
			{
				ft_graphic_pixel(ptr);
				if ((ptr->pos->y1 = ptr->pos->y1 - 1) == ptr->pos->y2)
					break ;
			}
	}
}

void	ft_line(t_mlx *ptr)
{
	int dx;

	if ((dx = ptr->pos->x2 - ptr->pos->x1) != 0)
	{
		if (dx > 0)
			ft_line_first(ptr, dx);
		else
			ft_line_second(ptr, dx);
	}
	else
		ft_line_last(ptr);
}
