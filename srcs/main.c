/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 18:32:40 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 19:41:46 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int fd_a;
	int fd_b;
	int fd_c;

	if (argc == 2)
	{
		fd_a = open(argv[1], O_RDONLY);
		if (fd_a == -1)
		{
			ft_putendl("Error : Le fichier passe en parametre n'existe pas.");
			exit(EXIT_FAILURE);
		}
		fd_b = open(argv[1], O_RDONLY);
		fd_c = open(argv[1], O_RDONLY);
		main_next(fd_a, fd_b, fd_c);
		close(fd_a);
		close(fd_b);
		close(fd_c);
	}
	else
		ft_putendl("usage: ./fdf target_file");
	return (EXIT_SUCCESS);
}

void	main_next(int fd_a, int fd_b, int fd_c)
{
	t_mlx	*ptr;
	int		nb_line;
	int		nb_number;

	nb_line = ft_count_nb_line(fd_a);
	nb_number = ft_count_nb_number(fd_b);
	ptr = ft_struct_init(fd_c, nb_line, nb_number);
	ptr = ft_graphic_init(ptr);
	ft_calc_z_max(ptr);
	ft_struct_free(ptr);
}
