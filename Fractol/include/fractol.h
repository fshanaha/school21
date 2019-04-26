/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:56:58 by srafe             #+#    #+#             */
/*   Updated: 2019/03/19 16:47:23 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <sys/uio.h>
# include "../Libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 1200
# define THREAD 120
# define THREAD_W 20

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			flag;
}				t_color;

typedef struct	s_reim
{
	double		cre;
	double		cim;
	double		newim;
	double		oldim;
	double		newre;
	double		oldre;
	double		pr;
	double		pi;
	double		rsqr;
	double		isqr;

}				t_reim;

typedef struct	s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	void		*img_ptr;
	int			*data;
	char		*img_data;
}				t_img;

typedef struct	s_zoom
{
	int			zoomiter;
	double		zoom;
	double		zoom_w;
	double		zoom_h;
	double		movex;
	double		movey;
	double		whalf;
	double		hhalf;
}				t_zoom;

typedef struct	s_mouse
{
	int			j_mouse;
}				t_mouse;

typedef struct	s_frl
{
	void		*mlx_ptr;
	void		*win;
	t_color		color;
	t_reim		reim;
	t_zoom		zoom;
	t_mouse		mouse;
	t_img		img;
	int			maxiterations;
	int			map;
	int			y;
	int			x;
	int			y_max;
	double		buff;
}				t_frl;

int				ft_exit(int i);
void			error(char *c);
void			julia(t_frl *f);
void			fhelp(void);
void			shift_key(int key, t_frl *f);
int				ft_deal(int key, t_frl *f);
void			make_map(t_frl *f);
void			mandelbrot(t_frl *f);
int				ft_mouse_deal(int key, int x, int y, t_frl *f);
t_frl			params(t_frl *f);
void			chech_color(int i, t_frl *f);
void			burning_ship(t_frl *f);
void			duobrot(t_frl *f);
void			triobrot(t_frl *f);
void			buffalo(t_frl *f);
int				move_julia(int x, int y, t_frl *f);
void			what_map(t_frl *f);

#endif
