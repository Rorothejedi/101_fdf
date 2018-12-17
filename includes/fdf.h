/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 18:33:57 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 20:39:19 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** -------------------------------------------
** DEFINES
** -------------------------------------------
*/

# define W_WIDTH      2560
# define W_HEIGHT     1400
# define NAME         "Wireframe 101 | FdF"

# define T_ISOMETRIC  'i'
# define T_CAVALIER   'c'
# define T_CABINET    'o'

# define K_A          0
# define K_S          1
# define K_D          2
# define K_Q          12
# define K_W          13
# define K_E          14
# define K_P          35
# define K_N          45
# define K_M          46
# define K_ESC        53

# define K_NP_PLUS    69
# define K_NP_MINUS   78
# define K_NP_TWO     84
# define K_NP_FOUR    86
# define K_NP_SIX     88
# define K_NP_EIGHT   91
# define K_PGUP       116
# define K_PGDN       121

# define K_ARR_LT     123
# define K_ARR_RT     124
# define K_ARR_DN     125
# define K_ARR_UP     126

# define M_CLIC_LT    1
# define M_CLIC_RT    2
# define M_WHEEL_DN   4
# define M_WHEEL_UP   5

/*
** -------------------------------------------
** INCLUDES
** -------------------------------------------
*/

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

/*
** -------------------------------------------
** STRUCTURE
** -------------------------------------------
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				nb_number;
	int				nb_line;
	int				**arr;
	struct s_param	*set;
	struct s_pos	*pos;
	struct s_color	*color;
}					t_mlx;

typedef struct		s_param
{
	char			*color_u;
	char			*color_d;
	int				color;
	char			type;
	int				size;
	float			depth;
	int				sensitivity;
	int				x_min;
	int				y_min;
	int				z_max;
	int				z_min;
}					t_param;

typedef struct		s_pos
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				count;
}					t_pos;

typedef struct		s_color
{
	int				c;
	char			*white;
	char			*red;
	char			*green;
	char			*blue;
	char			*pink;
	char			*yellow;
	char			*cyan;
	char			*black;
}					t_color;

/*
** -------------------------------------------
** PROTOTYPES
** -------------------------------------------
**
** main.c
*/

void				main_next(int fd_a, int fd_b, int fd_c);

/*
** ft_error.c
*/

void				ft_error(char *str);
void				ft_error_free(t_mlx *ptr, char *str);

/*
** ft_count.c
*/

int					ft_count_nb_line(int fd);
int					ft_count_nb_number(int fd);
int					ft_count_number(char *str);

/*
** ft_parser.c
*/

int					**ft_parser_extract_number(int fd, int nb_line, int y);

/*
** ft_struct.c
*/

t_mlx				*ft_struct_init(int fd, int nb_line, int nb_number);
t_param				*ft_struct_param(t_mlx *ptr);
t_pos				*ft_struct_pos(void);
t_color				*ft_struct_color(void);
void				ft_struct_free(t_mlx *ptr);

/*
** ft_graphic.c
*/

t_mlx				*ft_graphic_init(t_mlx *ptr);
int					ft_graphic_trace(t_mlx *ptr);
void				ft_graphic_display(t_mlx *ptr);
void				ft_graphic_pixel(t_mlx *ptr);

/*
** ft_string.c
*/

void				ft_graphic_string(t_mlx *ptr);
void				ft_graphic_string_color(t_mlx *ptr);
void				ft_graphic_gen_string(t_mlx *ptr, double w,
						double h, char *str);

/*
** ft_octant (Premiere partie de l'Algorithme de Bresenham)
*/

void				ft_octant_first(t_mlx *ptr, int dx, int dy);
void				ft_octant_second(t_mlx *ptr, int dx, int dy);
void				ft_octant_third(t_mlx *ptr, int dx, int dy);
void				ft_octant_fourth(t_mlx *ptr, int dx, int dy);

/*
** ft_octant_bis (Deuxieme partie de l'Algorithme de Bresenham)
*/

void				ft_octant_fifth(t_mlx *ptr, int dx, int dy);
void				ft_octant_sixth(t_mlx *ptr, int dx, int dy);
void				ft_octant_seventh(t_mlx *ptr, int dx, int dy);
void				ft_octant_eighth(t_mlx *ptr, int dx, int dy);

/*
** ft_line.c (Troisieme et derniere partie de l'Algorithme de Bresenham)
*/

void				ft_line(t_mlx *ptr);
void				ft_line_first(t_mlx *ptr, int dx);
void				ft_line_second(t_mlx *ptr, int dx);
void				ft_line_last(t_mlx *ptr);

/*
** ft_isometric.c (Type de projection isometrique)
*/

double				ft_isometric_x(int x, int y);
double				ft_isometric_y(int x, int y, int z);
t_mlx				*ft_isometric_width(t_mlx *ptr, int z1, int x, int y);
t_mlx				*ft_isometric_height(t_mlx *ptr, int z1, int x, int y);
void				ft_isometric_trace(t_mlx *ptr, int x, int y);

/*
** ft_cavalier.c (Type de projection cavaliere (oblique 1/2))
*/

double				ft_cavalier_x(int x, int y);
double				ft_cavalier_y(int x, int y);
t_mlx				*ft_cavalier_width(t_mlx *ptr, int z1, int x, int y);
t_mlx				*ft_cavalier_height(t_mlx *ptr, int z1, int x, int y);
void				ft_cavalier_trace(t_mlx *ptr, int x, int y);

/*
** ft_cabinet.c (Type de projection cabinet (oblique 2/2))
*/

double				ft_cabinet_x(int x, int y);
double				ft_cabinet_y(int x, int y);
t_mlx				*ft_cabinet_width(t_mlx *ptr, int z1, int x, int y);
t_mlx				*ft_cabinet_height(t_mlx *ptr, int z1, int x, int y);
void				ft_cabinet_trace(t_mlx *ptr, int x, int y);

/*
** ft_events.c
*/

int					ft_events_init(t_mlx *ptr);
int					ft_events_key(int keycode, t_mlx *ptr);
int					ft_events_mouse(int button, int x, int y, t_mlx *ptr);

/*
** ft_key.c
*/

t_mlx				*ft_key_move_isometric(t_mlx *ptr, int keycode);
t_mlx				*ft_key_move_oblique(t_mlx *ptr, int keycode);
t_mlx				*ft_key_color_up(t_mlx *ptr, int keycode);
t_mlx				*ft_key_color_down(t_mlx *ptr, int keycode);
t_mlx				*ft_key_other(t_mlx *ptr, int keycode);

/*
** ft_line.c
*/

void				ft_line(t_mlx *ptr);

/*
** ft_calc.c
*/

int					ft_calc_opt_display(t_mlx *ptr);
void				ft_calc_opt_display_size(t_mlx *ptr);
int					ft_calc_z_max(t_mlx *ptr);
int					ft_calc_z_min(t_mlx *ptr);

/*
** ft_color.c
*/

t_mlx				*ft_color_basic(t_mlx *ptr, int x, int y);
t_mlx				*ft_color_basic_next(t_mlx *ptr, double z_now);
t_mlx				*ft_color_choice(t_mlx *ptr, char *str, int i);
int					ft_color_rgbtoi(int r, int g, int b);

#endif
