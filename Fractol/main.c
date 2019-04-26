/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:38 by fshanaha          #+#    #+#             */
/*   Updated: 2019/03/19 16:24:41 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void		menu(t_frl *f)
{
	mlx_string_put(f->mlx_ptr, f->win, 10, 25, 0x00FFFFFF, "maxiterations:");
	mlx_string_put(f->mlx_ptr, f->win, 160, 25, 0x00FFFFFF,
													ft_itoa(f->maxiterations));
	mlx_string_put(f->mlx_ptr, f->win, 10, 45, 0x00FFFFFF, "Shift: Arrows");
	mlx_string_put(f->mlx_ptr, f->win, 10, 65, 0x00FFFFFF,
													"iterations: PgUp, PgDn");
	mlx_string_put(f->mlx_ptr, f->win, 10, 85, 0x00FFFFFF, "Zoom: +, -");
	mlx_string_put(f->mlx_ptr, f->win, 10, 105, 0xFF0000, "Color R (E,R):");
	mlx_string_put(f->mlx_ptr, f->win, 150, 105, 0xFF0000,
													ft_itoa(f->color.r));
	mlx_string_put(f->mlx_ptr, f->win, 10, 125, 0x00FF00, "Color G (F,G):");
	mlx_string_put(f->mlx_ptr, f->win, 150, 125, 0x00FF00,
													ft_itoa(f->color.g));
	mlx_string_put(f->mlx_ptr, f->win, 10, 145, 0x00FF, "Color B (V,B):");
	mlx_string_put(f->mlx_ptr, f->win, 150, 145, 0x00FF,
													ft_itoa(f->color.b));
	mlx_string_put(f->mlx_ptr, f->win, 10, 165, 0x00FFFFFF, "Change color: C");
	mlx_string_put(f->mlx_ptr, f->win, 10, 185, 0x00FFFFFF, "Set color RED: Z");
	mlx_string_put(f->mlx_ptr, f->win, 10, 205, 0x00FFFFFF, "Reset map: TAB");
	mlx_string_put(f->mlx_ptr, f->win, 10, 225, 0x00FFFFFF, "Change map: HOME\
																	, END");
	what_map(f);
}

t_frl		params(t_frl *f)
{
	f->img.bpp = 32;
	f->img.size_line = HEIGHT * 4;
	f->img.endian = 1;
	f->zoom.zoom = 0.2;
	f->zoom.zoomiter = 0;
	f->zoom.movex = 0;
	f->zoom.movey = 0;
	f->color.r = 120;
	f->color.g = 100;
	f->color.b = 10;
	f->maxiterations = 20;
	f->color.flag = 0;
	f->zoom.whalf = WIDTH / 2;
	f->zoom.hhalf = HEIGHT / 2;
	f->reim.cre = -0.70176;
	f->reim.cim = -0.3842;
	return (*f);
}

void		make_map(t_frl *f)
{
	mlx_clear_window(f->mlx_ptr, f->win);
	if (f->map == 0)
		julia(f);
	else if (f->map == 1)
		mandelbrot(f);
	else if (f->map == 2)
		burning_ship(f);
	else if (f->map == 3)
		duobrot(f);
	else if (f->map == 4)
		triobrot(f);
	else if (f->map == 5)
		buffalo(f);
	menu(f);
}

void		card_selection(int argc, char **argv, t_frl *f)
{
	if (argc != 2)
		fhelp();
	else if (ft_strcmp("julia", argv[1]) == 0)
		f->map = 0;
	else if (ft_strcmp("mandelbrot", argv[1]) == 0)
		f->map = 1;
	else if (ft_strcmp("burning_ship", argv[1]) == 0)
		f->map = 2;
	else if (ft_strcmp("duobrot", argv[1]) == 0)
		f->map = 3;
	else if (ft_strcmp("triobrot", argv[1]) == 0)
		f->map = 4;
	else if (ft_strcmp("buffalo", argv[1]) == 0)
		f->map = 5;
	else
		fhelp();
}

int			main(int argc, char **argv)
{
	t_frl	*f;

	if (!(f = (t_frl *)malloc(sizeof(t_frl))))
		error("I can\'t malloc((");
	card_selection(argc, argv, f);
	*f = params(f);
	f->mlx_ptr = mlx_init();
	f->win = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fractol");
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.img_data = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
						&f->img.size_line, &f->img.endian);
	f->img.data = (int *)f->img.img_data;
	f->mouse.j_mouse = 0;
	make_map(f);
	mlx_hook(f->win, 2, 1L << 0, ft_deal, f);
	mlx_hook(f->win, 4, 0, ft_mouse_deal, f);
	mlx_hook(f->win, 6, 1L < 6, move_julia, f);
	mlx_hook(f->win, 17, 1L << 17, ft_exit, 0);
	mlx_loop(f->mlx_ptr);
	return (0);
}
