/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:53:53 by erli              #+#    #+#             */
/*   Updated: 2018/12/11 16:24:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlxadd.h"
#include <pthread.h>

# define IMG_WIDTH 512
# define IMG_HEIGHT 512
# define WIN_STAT_WIDTH 300
# define WIN_STAT_HEIGHT 720
# define WIN_STAT_TEXT_COLOUR "0x00ffffff"
# define DEFAULT_NUM_MAX_ITER 50
# define DEFAULT_X_AMPLITUDE 3
# define MAX_ZOOM 655360000
# define ZOOM_INCR 1.10

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
	long double		zoom;
	long double		zoom_incr;
	long double		zoom_decr;
	long double		o_re;
	long double		o_im;
	long double		qx;
	long double		qy;
	long double		c_re;
	long double		c_im;
	t_colour		*grad;
	t_colour		(*cg)(struct s_fra_param *, int n);
	double			p1;
	double			p2;
	double			p3;
	double			p4;
	double			p5;
	int				count;
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
t_colour		*fra_make_grad_1(void);
t_colour		fra_cg_bw(t_fra_param *param, int n);
t_colour		fra_cg_grad(t_fra_param *param, int n);
int				fra_iter_julia(t_fra_param *param, int x, int y);
void			*fra_draw1(void *arg);
void			*fra_draw2(void *arg);
void			*fra_draw3(void *arg);
void			*fra_draw4(void *arg);
void			*fra_draw5(void *arg);
void			fra_draw(t_fra_param *param);

#endif
