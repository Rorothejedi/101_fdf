/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_events.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 17:55:21 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 18:46:46 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Gere les evenements.
*/

int		ft_events_init(t_mlx *ptr)
{
	mlx_hook(ptr->win, 2, (1L << 0), ft_events_key, (void*)ptr);
	mlx_mouse_hook(ptr->win, ft_events_mouse, ptr);
	return (0);
}

/*
** Permet de gerer les differents evenements au clavier (deplacements, quitter
** , zoom, changement de type de projection, modification sensibilite et de
** l'axe Z).
*/

int		ft_events_key(int keycode, t_mlx *ptr)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		ft_struct_free(ptr);
		exit(EXIT_SUCCESS);
	}
	mlx_clear_window(ptr->mlx, ptr->win);
	if (ptr->set->type == T_ISOMETRIC)
		ptr = ft_key_move_isometric(ptr, keycode);
	else if (ptr->set->type == T_CAVALIER || ptr->set->type == T_CABINET)
		ptr = ft_key_move_oblique(ptr, keycode);
	ptr = ft_key_color_up(ptr, keycode);
	ptr = ft_key_color_down(ptr, keycode);
	ptr = ft_key_other(ptr, keycode);
	ft_graphic_trace(ptr);
	return (0);
}

/*
** Permet de gerer des evenements a la souris (zoom et clic)
*/

int		ft_events_mouse(int button, int x, int y, t_mlx *ptr)
{
	if (button != M_CLIC_LT)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		if (button == M_WHEEL_DN)
			ptr->set->size += ptr->set->sensitivity;
		else if (button == M_WHEEL_UP && ptr->set->size > 0)
			ptr->set->size -= ptr->set->sensitivity;
		ft_graphic_trace(ptr);
	}
	else if (button == M_CLIC_LT && ptr->pos->count == 0)
	{
		ptr->pos->x1 = x;
		ptr->pos->y1 = y;
		ptr->pos->count++;
	}
	else if (button == M_CLIC_LT && ptr->pos->count == 1)
	{
		ptr->pos->x2 = x;
		ptr->pos->y2 = y;
		ptr->pos->count = 0;
		ft_line(ptr);
		ft_graphic_gen_string(ptr, 45, 88, "Press any key to clean");
	}
	return (0);
}
