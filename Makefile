NAME = fdf

LIB_FOLDER = libft
LIB = $(LIB_FOLDER)/libft.a

LIBX_FOLDER = minilibx_macos
LIBX = $(LIBX_FOLDER)/libmlx.a

FLAGS = -Wall -Wextra -Werror
XFLAGS = -framework OpenGL -framework AppKit
CC = gcc

SRCS_FOLDER = srcs
SRCS = $(SRCS_FOLDER)/main.c									\
			 $(SRCS_FOLDER)/ft_error.c							\
			 $(SRCS_FOLDER)/ft_count.c							\
			 $(SRCS_FOLDER)/ft_parser.c							\
			 $(SRCS_FOLDER)/ft_graphic.c						\
			 $(SRCS_FOLDER)/ft_string.c							\
			 $(SRCS_FOLDER)/ft_struct.c							\
			 $(SRCS_FOLDER)/ft_events.c							\
			 $(SRCS_FOLDER)/ft_key.c							\
			 $(SRCS_FOLDER)/ft_line.c							\
			 $(SRCS_FOLDER)/ft_octant.c							\
			 $(SRCS_FOLDER)/ft_octant_bis.c						\
			 $(SRCS_FOLDER)/ft_isometric.c						\
			 $(SRCS_FOLDER)/ft_cavalier.c						\
			 $(SRCS_FOLDER)/ft_cabinet.c						\
			 $(SRCS_FOLDER)/ft_calc.c							\
			 $(SRCS_FOLDER)/ft_color.c

OBJS_FOLDER = objs
OBJS = $(SRCS:$(SRCS_FOLDER)/%.c=$(OBJS_FOLDER)/%.o)

INC_FOLDER = includes
INCLUDES = $(INC_FOLDER)/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C $(LIB_FOLDER)
	@ make -C $(LIBX_FOLDER)
	@ $(CC) $(FLAGS) -I $(INCLUDES) -o $@ $^ $(LIB) $(LIBX) $(XFLAGS)
	@ echo "Compilation $(NAME) ..."\
	"...................................................... \033[32m[OK]\033[0m"
	@ echo "Compilation $(LIBX_FOLDER) ..."\
	"........................................... \033[32m[OK]\033[0m"

$(OBJS_FOLDER):
	@ mkdir $(OBJS_FOLDER)

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c | $(OBJS_FOLDER)
	@ $(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(OBJS_FOLDER)
	@ make -C $(LIB_FOLDER) clean
	@ make -C $(LIBX_FOLDER) clean
	@ echo "Delete *.o ($(NAME)) ..."\
	"..................................................... \033[32m[OK]\033[0m"

fclean: clean
	@ rm -f $(NAME) $(LIB) $(LIBX)
	@ echo "Delete $(LIB) ...."\
	"................................................ \033[32m[OK]\033[0m"
	@ echo "Delete $(NAME) ......."\
	"....................................................... \033[32m[OK]\033[0m"

re: fclean all
