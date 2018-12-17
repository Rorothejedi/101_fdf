/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 18:25:38 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:29:58 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Permet de determiner la couleur actuelle avec le rapport entre la valeur
** de z et celle de z_max ou z_min.
*/

t_mlx	*ft_color_basic(t_mlx *ptr, int x, int y)
{
	double	z_now;
	int		i;

	z_now = ptr->arr[y - ptr->set->y_min][x - ptr->set->x_min];
	if (ptr->set->depth >= 0.1 && (z_now * ptr->set->depth > 0))
	{
		i = 255 * z_now / ptr->set->z_max;
		if (i >= 0 && i <= 255)
			ptr = ft_color_choice(ptr, ptr->set->color_u, i);
	}
	else if (ptr->set->depth <= -0.1 && z_now < 0)
	{
		i = 255 * z_now / ptr->set->z_min;
		if (i >= 0 && i <= 255)
			ptr = ft_color_choice(ptr, ptr->set->color_u, i);
	}
	else
		ptr = ft_color_basic_next(ptr, z_now);
	return (ptr);
}

t_mlx	*ft_color_basic_next(t_mlx *ptr, double z_now)
{
	int i;

	if (ptr->set->depth >= 0.1 && z_now < 0)
	{
		i = 255 * z_now / ptr->set->z_min;
		if (i >= 0 && i <= 255)
			ptr = ft_color_choice(ptr, ptr->set->color_d, i);
	}
	else if (ptr->set->depth <= -0.1 && z_now > 0)
	{
		i = 255 * z_now / ptr->set->z_max;
		if (i >= 0 && i <= 255)
			ptr = ft_color_choice(ptr, ptr->set->color_d, i);
	}
	else
		ptr->color->c = ft_color_rgbtoi(255, 255, 255);
	return (ptr);
}

/*
** Permet de modifier les couleurs en fonction de ces caracteristiques RGB.
*/

t_mlx	*ft_color_choice(t_mlx *ptr, char *str, int i)
{
	int color;

	color = 16777215;
	if (str == ptr->color->red)
		color = ft_color_rgbtoi(255, 255 - i, 255 - i);
	else if (str == ptr->color->green)
		color = ft_color_rgbtoi(255 - i, 255, 255 - i);
	else if (str == ptr->color->blue)
		color = ft_color_rgbtoi(255 - i, 255 - i, 255);
	else if (str == ptr->color->cyan)
		color = ft_color_rgbtoi(255 - i, 255, 255);
	else if (str == ptr->color->pink)
		color = ft_color_rgbtoi(255, 255 - i, 255);
	else if (str == ptr->color->yellow)
		color = ft_color_rgbtoi(255, 255, 255 - i);
	else if (str == ptr->color->black)
		color = ft_color_rgbtoi(255 - i, 255 - i, 255 - i);
	else if (str == ptr->color->white)
		color = ft_color_rgbtoi(255, 255, 255);
	ptr->color->c = color;
	return (ptr);
}

/*
** Permet de convertir des couleurs RGB (red, green, blue) en int pour que la
** couleur puisse etre interpreter par la mlx.
*/

int		ft_color_rgbtoi(int r, int g, int b)
{
	int result;

	result = r;
	result = (result << 8) | g;
	result = (result << 8) | b;
	return (result);
}
