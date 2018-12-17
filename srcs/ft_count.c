/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:25:39 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 18:58:06 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Compte le nombre de ligne sur l'axe y dans la grille passee en parametre.
*/

int		ft_count_nb_line(int fd)
{
	int		nb_line;
	char	*line;

	nb_line = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
		free(line);
		line = NULL;
	}
	return (nb_line);
}

/*
** Compte le nombre de nombre que contient chaque ligne de la grille (axe x).
** Fait egalement les verification d'erreurs (check qu'il s'agit bien d'un
** rectangle).
*/

int		ft_count_nb_number(int fd)
{
	int		nb_number;
	char	*line;

	nb_number = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (nb_number == 0 || nb_number == ft_count_number(line))
			nb_number = ft_count_number(line);
		else if (nb_number != 0 && nb_number != ft_count_number(line))
		{
			free(line);
			line = NULL;
			ft_error("Error : La figure passee en parametre n'est pas valide.");
		}
		free(line);
		line = NULL;
	}
	return (nb_number);
}

/*
** Fonction qui permet de compter les nombres present dans une grille sans
** avoir besoin d'utiliser un ft_strsplit qui est ici excessif (malloc).
*/

int		ft_count_number(char *str)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}
