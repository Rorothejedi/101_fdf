/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 01:31:02 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:19:48 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Permet de n'afficher que les lignes qui apparaisse dont au moins un point
** apparait dans la fenetre.
*/

int		ft_calc_opt_display(t_mlx *ptr)
{
	if (!((ptr->pos->x1 < 0 || ptr->pos->x1 > W_WIDTH
	|| ptr->pos->y1 < 0 || ptr->pos->y1 > W_HEIGHT - (W_HEIGHT * 17 / 100))
	&& (ptr->pos->x2 < 0 || ptr->pos->x2 > W_WIDTH
	|| ptr->pos->y2 < 0 || ptr->pos->y2 > W_HEIGHT - (W_HEIGHT * 17 / 100))))
		return (1);
	return (0);
}

/*
** Permet de calculer une size par defaut en fonction de la longueur maximum
** d'une map.
*/

void	ft_calc_opt_display_size(t_mlx *ptr)
{
	int size;
	int max;

	size = 40;
	max = (ptr->nb_number > ptr->nb_line) ? ptr->nb_number : ptr->nb_line;
	while ((max = max - 20) > 0)
		size -= 3;
	ptr->set->size = size;
}

/*
** Retourne la valuer maximum de z dans la map.
*/

int		ft_calc_z_max(t_mlx *ptr)
{
	int x;
	int y;
	int max;

	max = 0;
	y = -1;
	while (++y < ptr->nb_line)
	{
		x = -1;
		while (++x < ptr->nb_number)
		{
			if (ptr->arr[y][x] > max)
				max = ptr->arr[y][x];
		}
	}
	return (max);
}

/*
** Retourne la valuer maximum de z dans la map.
*/

int		ft_calc_z_min(t_mlx *ptr)
{
	int x;
	int y;
	int min;

	min = 0;
	y = -1;
	while (++y < ptr->nb_line)
	{
		x = -1;
		while (++x < ptr->nb_number)
		{
			if (ptr->arr[y][x] < min)
				min = ptr->arr[y][x];
		}
	}
	return (min);
}
