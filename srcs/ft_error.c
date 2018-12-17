/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:57:11 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:20:00 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Permet de quitter le programme en cas d'erreur et d'afficher un message a
** l'utilisateur.
*/

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

/*
** Permet de quitter proprement le programme en cas d'erreur et d'afficher un
** message a l'utilisateur.
*/

void	ft_error_free(t_mlx *ptr, char *str)
{
	ft_putendl(str);
	ft_arrdel_i(ptr->arr, ptr->nb_line);
	free(ptr->set);
	free(ptr->pos);
	free(ptr->color);
	ptr->set = NULL;
	ptr->pos = NULL;
	ptr->color = NULL;
	free(ptr);
	ptr = NULL;
	exit(EXIT_FAILURE);
}
