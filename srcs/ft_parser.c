/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:03:10 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:32:21 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Permet de recuperer les nombres inclus dans la grille passee en parametre
** dans un tableau d'entier a deux dimensions.
** Elle verifie egalement que les coordonnes passees dans le fichier en
** parametre sont valides (uniquement des nombres).
*/

int			**ft_parser_extract_number(int fd, int nb_line, int y)
{
	char	*line;
	char	**temp_array;
	int		**array;
	int		x;

	if (!(array = malloc(sizeof(array) * nb_line)))
		ft_error("Error : Echec d'allocation memoire (malloc).");
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		if (!(array[++y] = malloc(sizeof(*array) * ft_count_number(line))))
			ft_error("Error : Echec d'allocation memoire (malloc).");
		temp_array = ft_strsplit(line, ' ');
		while (++x < ft_count_number(line))
		{
			if (ft_isnbr(temp_array[x]) == 0)
				ft_error("Error : Les coordonnes passees sont invalides.");
			array[y][x] = ft_getnbr(temp_array[x]);
		}
		ft_arrdel_c(temp_array, ft_count_number(line));
		free(line);
		line = NULL;
	}
	return (array);
}
