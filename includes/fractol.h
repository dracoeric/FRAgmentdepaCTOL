/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:53:53 by erli              #+#    #+#             */
/*   Updated: 2018/12/13 17:52:29 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlxadd.h"
# include <pthread.h>

# define IMG_WIDTH 512
# define IMG_HEIGHT 512
# define WIN_STAT_WIDTH 300
# define WIN_STAT_HEIGHT 720
# define WIN_STAT_TEXT_COLOUR "0x00ffffff"
# define DEFAULT_NUM_MAX_ITER 50
# define DEFAULT_X_AMPLITUDE 3
# define MAX_ZOOM 200000000000000
# define ZOOM_INCR 1.2
# define NUM_MAX_THREAD 5

enum	e_fra_type
{
	JULIA = 1,
	MANDELBROT = 2,
	MANDELDROP = 3,
	MANDEL2BROT = 4,
	BURNING = 5,
	NOT_SUPPORTED = 6
};

typedef	struct	s_fra_list
{
	t_pixcoord			*pix;
	struct s_fra_list	*next;
}				t_fra_list;

typedef	struct	s_fra_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*win_stat_ptr;
	t_colour		stat_colour;
	t_img			*img;
	unsigned char	key_pressed;
	unsigned char	key_pressed2;
	t_pixcoord		*pointer;
	enum e_fra_type	type;
	int				num_max_iter;
	double			zoom;
	double			zoom_incr;
	double			zoom_decr;
	double			o_re;
	double			o_im;
	double			qx;
	double			qy;
	double			c_re;
	double			c_im;
	t_colour		*grad;
	t_colour		(*cg)(struct s_fra_param *, int n);
	int				(*iter)(struct s_fra_param *, int, int);
	double			count;
	double			*thread_time;
	pthread_t		*thread0;
}				t_fra_param;

int				fra_close(void *param);
int				fra_free_param(t_fra_param **param, int cas, int settings);
t_fra_param		*fra_init_param(enum e_fra_type type);
int				fra_key_press(int key, void *param);
int				fra_key_close(int key, void *param);
int				fra_key_release(int key, void *param);
int				fra_mouse_move(int x, int y, void *param);
int				fra_mouse_press(int button, int x, int y, void *param);
void			fra_print_stat(t_fra_param *param);
enum e_fra_type	fra_type(char *str);
double			fra_pix_to_re(t_fra_param *param, int px);
double			fra_pix_to_im(t_fra_param *param, int py);
t_colour		*fra_make_grad_1(void);
t_colour		*fra_change_grad(t_colour *grad, int n);
t_colour		fra_cg_bw(t_fra_param *param, int n);
t_colour		fra_cg_grad(t_fra_param *param, int n);
void			fra_pixel_put_img(t_img *img, int x, int y, t_colour colour);
int				fra_iter_julia(t_fra_param *param, int x, int y);
int				fra_iter_mandelbrot(t_fra_param *param, int x, int y);
int				fra_iter_mandel2brot(t_fra_param *param, int x, int y);
int				fra_iter_burning_ship(t_fra_param *param, int x, int y);
int				fra_iter_mandeldrop(t_fra_param *param, int x, int y);
void			fra_draw(t_fra_param *param);

#endif
