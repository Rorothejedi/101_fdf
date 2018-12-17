/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 17:35:36 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:15:48 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Gere les mouvements (haut, bas, gauche, droite) pendant la projection
** isometrique.
*/

t_mlx	*ft_key_move_isometric(t_mlx *ptr, int keycode)
{
	if (keycode == K_ARR_UP || keycode == K_W || keycode == K_NP_EIGHT)
	{
		ptr->set->x_min -= ptr->set->sensitivity;
		ptr->set->y_min -= ptr->set->sensitivity;
	}
	else if (keycode == K_ARR_DN || keycode == M_CLIC_LT || keycode == K_NP_TWO)
	{
		ptr->set->y_min += ptr->set->sensitivity;
		ptr->set->x_min += ptr->set->sensitivity;
	}
	else if (keycode == K_ARR_LT || keycode == K_A || keycode == K_NP_FOUR)
	{
		ptr->set->x_min -= ptr->set->sensitivity;
		ptr->set->y_min += ptr->set->sensitivity;
	}
	else if (keycode == K_ARR_RT || keycode == K_D || keycode == K_NP_SIX)
	{
		ptr->set->x_min += ptr->set->sensitivity;
		ptr->set->y_min -= ptr->set->sensitivity;
	}
	return (ptr);
}

/*
** Gere les mouvements (haut, bas, gauche, droite) pendant la projection
** cavaliere et cabinet.
*/

t_mlx	*ft_key_move_oblique(t_mlx *ptr, int keycode)
{
	if (keycode == K_ARR_UP || keycode == K_W || keycode == K_NP_EIGHT)
		ptr->set->y_min -= ptr->set->sensitivity;
	else if (keycode == K_ARR_DN || keycode == K_S || keycode == K_NP_TWO)
		ptr->set->y_min += ptr->set->sensitivity;
	else if (keycode == K_ARR_LT || keycode == K_A || keycode == K_NP_FOUR)
		ptr->set->x_min -= ptr->set->sensitivity;
	else if (keycode == K_ARR_RT || keycode == K_D || keycode == K_NP_SIX)
		ptr->set->x_min += ptr->set->sensitivity;
	return (ptr);
}

/*
** Gere les changement des couleurs du niveau maximum (touche M)
*/

t_mlx	*ft_key_color_up(t_mlx *ptr, int keycode)
{
	if (keycode == K_M)
	{
		if (ptr->set->color_u == ptr->color->white)
			ptr->set->color_u = ptr->color->red;
		else if (ptr->set->color_u == ptr->color->red)
			ptr->set->color_u = ptr->color->green;
		else if (ptr->set->color_u == ptr->color->green)
			ptr->set->color_u = ptr->color->blue;
		else if (ptr->set->color_u == ptr->color->blue)
			ptr->set->color_u = ptr->color->pink;
		else if (ptr->set->color_u == ptr->color->pink)
			ptr->set->color_u = ptr->color->yellow;
		else if (ptr->set->color_u == ptr->color->yellow)
			ptr->set->color_u = ptr->color->cyan;
		else if (ptr->set->color_u == ptr->color->cyan)
			ptr->set->color_u = ptr->color->black;
		else if (ptr->set->color_u == ptr->color->black)
			ptr->set->color_u = ptr->color->white;
	}
	return (ptr);
}

/*
** Gere les changement des couleurs du niveau maximum (touche M)
*/

t_mlx	*ft_key_color_down(t_mlx *ptr, int keycode)
{
	if (keycode == K_N)
	{
		if (ptr->set->color_d == ptr->color->white)
			ptr->set->color_d = ptr->color->red;
		else if (ptr->set->color_d == ptr->color->red)
			ptr->set->color_d = ptr->color->green;
		else if (ptr->set->color_d == ptr->color->green)
			ptr->set->color_d = ptr->color->blue;
		else if (ptr->set->color_d == ptr->color->blue)
			ptr->set->color_d = ptr->color->pink;
		else if (ptr->set->color_d == ptr->color->pink)
			ptr->set->color_d = ptr->color->yellow;
		else if (ptr->set->color_d == ptr->color->yellow)
			ptr->set->color_d = ptr->color->cyan;
		else if (ptr->set->color_d == ptr->color->cyan)
			ptr->set->color_d = ptr->color->black;
		else if (ptr->set->color_d == ptr->color->black)
			ptr->set->color_d = ptr->color->white;
	}
	return (ptr);
}

/*
** Gere les autres touches (+ et - pour augmenter ou diminuer la semsibilite,
** Q et E pour augmenter ou diminuer la profondeur, touche P pour changer de
** type de projection).
*/

t_mlx	*ft_key_other(t_mlx *ptr, int keycode)
{
	if (keycode == K_NP_PLUS && ptr->set->sensitivity < 9)
		ptr->set->sensitivity++;
	else if (keycode == K_NP_MINUS && ptr->set->sensitivity > 1)
		ptr->set->sensitivity--;
	else if (keycode == K_Q || keycode == 121)
		ptr->set->depth -= ptr->set->sensitivity * 0.1;
	else if (keycode == K_E || keycode == 116)
		ptr->set->depth += ptr->set->sensitivity * 0.1;
	else if (keycode == K_P)
	{
		if (ptr->set->type == T_ISOMETRIC)
			ptr->set->type = T_CAVALIER;
		else if (ptr->set->type == T_CAVALIER)
			ptr->set->type = T_CABINET;
		else if (ptr->set->type == T_CABINET)
			ptr->set->type = T_ISOMETRIC;
	}
	return (ptr);
}
