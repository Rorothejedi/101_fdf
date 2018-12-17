/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_string.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 19:13:22 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 20:21:43 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Affichage des indication fixes sur l'interface.
*/

void	ft_graphic_string(t_mlx *ptr)
{
	ft_graphic_gen_string(ptr, 7.5, 85.5, "Projection : ");
	ft_graphic_gen_string(ptr, 7.5, 87, "Sensitivity : ");
	ft_graphic_gen_string(ptr, 7.5, 88, "___________________________________");
	ft_graphic_gen_string(ptr, 7.5, 90, "+ : more sensitivity");
	ft_graphic_gen_string(ptr, 7.5, 91.5, "- : less sensitivity");
	ft_graphic_gen_string(ptr, 7.5, 94.5, "ESC : exit");
	ft_graphic_gen_string(ptr, 77.5, 85.5, "Top color :");
	ft_graphic_gen_string(ptr, 77.5, 87, "Bottom color :");
	ft_graphic_gen_string(ptr, 77.5, 88, "___________________________________");
	ft_graphic_gen_string(ptr, 77.5, 90, "Mouse wheel : zoom");
	ft_graphic_gen_string(ptr, 77.5, 93, "N : change top color");
	ft_graphic_gen_string(ptr, 77.5, 94.5, "M : change bottom color");
	ft_graphic_gen_string(ptr, 88, 90, "W : up");
	ft_graphic_gen_string(ptr, 88, 91.5, "S : down");
	ft_graphic_gen_string(ptr, 88, 93, "A : left");
	ft_graphic_gen_string(ptr, 88, 94.5, "D : right");
}

/*
** Affichage des indication qui peuvenet etre mofifie a la volee sur
** l'interface. Affichage en couleur.
*/

void	ft_graphic_string_color(t_mlx *ptr)
{
	ptr->set->color = ft_color_rgbtoi(0, 255, 0);
	if (ptr->set->type == T_ISOMETRIC)
		ft_graphic_gen_string(ptr, 17.7, 85.5, "isometric");
	else if (ptr->set->type == T_CAVALIER)
		ft_graphic_gen_string(ptr, 18.1, 85.5, "cavalier");
	else if (ptr->set->type == T_CABINET)
		ft_graphic_gen_string(ptr, 18.4, 85.5, "cabinet");
	ft_graphic_gen_string(ptr, 20.8, 87, ft_itoa(ptr->set->sensitivity));
	ft_graphic_gen_string(ptr, 89, 85.5, ptr->set->color_u);
	ft_graphic_gen_string(ptr, 89, 87, ptr->set->color_d);
	ptr->set->color = ft_color_rgbtoi(255, 255, 255);
}

void	ft_graphic_gen_string(t_mlx *ptr, double w, double h, char *str)
{
	mlx_string_put(ptr->mlx, ptr->win, W_WIDTH * w / 100
		, W_HEIGHT * h / 100, ptr->set->color, str);
}
