#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 10:43:47 by erli              #+#    #+#              #
#    Updated: 2018/12/13 14:24:03 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	fractol

SRCSDIR			=	srcs

OBJSDIR			=	objs

SRCS			=	mlx_line_put.c		mlx_str_to_colour.c							\
					mlx_line_put_img.c	mlx_pixel_put_img.c	mlx_img_create.c		\
					mlx_iso_proj.c		mlx_para_proj.c		mlx_colour_blue.c		\
															mlx_colour_gradiant.c	\
					fra_close.c			fra_free_param.c	fra_init_param.c		\
					fra_key_press.c		fra_key_release.c	fra_mouse_move.c		\
					fra_mouse_press.c	fra_type.c			fra_print_stat.c		\
					fra_pix_to_re.c		fra_pix_to_im.c		fra_iter_julia.c		\
					fra_cg_bw.c			fra_cg_grad.c		fra_draw.c				\
					fra_make_grad_1.c	fra_pixel_put_img.c	fra_key_close.c			\
					fra_iter_mandelbrot.c					fra_iter_mandeldrop.c	\
					fra_iter_mandel2brot.c					fra_iter_burning_ship.c \
					fra_change_grad.c						main.c				

OBJS			=	$(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

RM				=	rm -f

INCL			=	-I includes/ -I libft/includes -I minilibx_macos/

LIB				=	-Lminilibx_macos/ -lmlx -Llibft/ -lft -lpthread

FRAMEWORK		=	-framework OpenGL -framework AppKit

LIBFT			=	libft/libft.a

LIBMLX			=	minilibx_macos/libmlx.a


all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(LIBMLX) $(OBJS) includes/fractol.h includes/mlxadd.h
					$(CC) $(CFLAGS) $(INCL) $(LIB) -o $(NAME) $(OBJS) $(FRAMEWORK)

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/fractol.h includes/mlxadd.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAGS) $(INCL) -o $@ $<

$(LIBFT)		:	
					make -C libft/ && make -C libft/ clean

$(LIBMLX)		:
					make -C minilibx_macos

val				:	$(LIBFT) $(LIBMLX) $(OBJS) includes/fractol.h includes/mlxadd.h
					$(CC) -g $(CFLAGS) $(INCL) $(LIB) -o $(NAME) $(OBJS) $(FRAMEWORK)

fast			:	
					make -C fast

sanit			:	$(LIBFT) $(LIBMLX) $(OBJS) includes/fractol.h includes/mlxadd.h
					$(CC) $(CFLAGS) $(INCL) $(LIB) -o $(NAME) $(OBJS) $(FRAMEWORK) \
					-g -fsanitize=address

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

delsav			:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*
					$(RM) */\#*

.PHONY			:	clean val fast