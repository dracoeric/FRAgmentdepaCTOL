/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:53:53 by erli              #+#    #+#             */
/*   Updated: 2018/12/10 12:07:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlxadd.h"

# define IMG_WIDTH 1080
# define IMG_HEIGHT 720
# define WIN_STAT_WIDTH 300
# define WIN_STAT_HEIGHT 720
# define WIN_STAT_TEXT_COLOUR "0x00ffffff"
# define DEFAULT_NUM_MAX_ITER 50
# define DEFAULT_X_AMPLITUDE 3
# define MAX_ZOOM 65536

enum	e_fra_type
{
	NOT_SUPPORTED = -1,
	JULIA = 0,
	MANDELBROT = 1
};

typedef	struct	s_fra_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*win_stat_ptr;
	t_colour		stat_colour;
	t_img			*img;
	unsigned char	key_pressed;
	t_pixcoord		*pointer;
	enum e_fra_type	type;	
	int				num_max_iter;
	int				zoom;
	long double		qx;
	long double		qy;
	long double		c_re;
	long double		c_im;
	t_colour		(*cg)(int n);
}				t_fra_param;

int				fra_close(void *param);
int				fra_free_param(t_fra_param **param, int cas, int settings);
t_fra_param		*fra_init_param(enum e_fra_type type);
int				fra_key_press(int key, void *param);
int				fra_key_release(int key, void *param);
int				fra_mouse_move(int x, int y, void *param);
int				fra_mouse_press(int button, int x, int y, void *param);
void			fra_print_stat(t_fra_param *param);
enum e_fra_type	fra_type(char *str);
long double		fra_pix_to_re(t_fra_param *param, int px);
long double		fra_pix_to_im(t_fra_param *param, int py);

#endif
