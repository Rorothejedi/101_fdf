/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_graphic.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:42:26 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:38:27 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Initialisation du serveur graphique et ouverture de la fenetre.
** Initialisation des evenements (ft_events).
*/

t_mlx	*ft_graphic_init(t_mlx *ptr)
{
	if ((ptr->mlx = mlx_init()) == NULL)
		ft_error_free(ptr, "Error : Echec d'initialisation serveur graphique");
	if ((ptr->win = mlx_new_window(ptr->mlx, W_WIDTH, W_HEIGHT, NAME)) == NULL)
		ft_error_free(ptr, "Error : Echec d'initialisation de la fenetre");
	ft_calc_opt_display_size(ptr);
	ft_graphic_trace(ptr);
	ft_events_init(ptr);
	mlx_loop(ptr->mlx);
	return (ptr);
}

/*
** Affichage des pixels en fonction de leur position et de leur taille a partir
** de la structure t_mlx.
*/

int		ft_graphic_trace(t_mlx *ptr)
{
	int		x;
	int		y;

	y = ptr->set->y_min - 1;
	while (++y < (ptr->nb_line + ptr->set->y_min))
	{
		x = ptr->set->x_min - 1;
		while (++x < (ptr->nb_number + ptr->set->x_min))
		{
			ptr = ft_color_basic(ptr, x, y);
			if (ptr->set->type == T_ISOMETRIC)
				ft_isometric_trace(ptr, x, y);
			else if (ptr->set->type == T_CAVALIER)
				ft_cavalier_trace(ptr, x, y);
			else if (ptr->set->type == T_CABINET)
				ft_cabinet_trace(ptr, x, y);
		}
	}
	ft_graphic_display(ptr);
	return (0);
}

/*
** Affichage d'une image de fond (noire) pour l'interface du bas.
** Affichage d'une ligne de demarcation de l'interface.
*/

void	ft_graphic_display(t_mlx *ptr)
{
	void	*img;

	if ((img = mlx_new_image(ptr->mlx, W_WIDTH, (W_HEIGHT * 17 / 100))) == NULL)
		ft_error_free(ptr, "Error : Echec d'initialisation de l'image");
	mlx_put_image_to_window(ptr->mlx, ptr->win, img, 0, W_HEIGHT
		- (W_HEIGHT * 17 / 100));
	ft_graphic_string(ptr);
	ft_graphic_string_color(ptr);
	ptr->pos->x1 = 0;
	ptr->pos->y1 = W_HEIGHT - (W_HEIGHT * 17 / 100);
	ptr->pos->x2 = W_WIDTH;
	ptr->pos->y2 = W_HEIGHT - (W_HEIGHT * 17 / 100);
	ptr->color->c = ft_color_rgbtoi(255, 255, 255);
	ft_line(ptr);
}

/*
** Permet l'affichage d'un pixel simple au coordonnees x1 et y1 incluses dans
** la structure 'ptr'.
*/

void	ft_graphic_pixel(t_mlx *ptr)
{
	mlx_pixel_put(ptr->mlx, ptr->win, ptr->pos->x1,
		ptr->pos->y1, ptr->color->c);
}
