/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:46:20 by fshanaha          #+#    #+#             */
/*   Updated: 2019/03/19 16:36:00 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	error(char *c)
{
	ft_putendl(c);
	exit(0);
}

int		ft_exit(int i)
{
	exit(i);
	return (0);
}

void	fhelp(void)
{
	ft_putstr("usage: julia, mandelbrot, burning_ship, \
duobrot, triobrot, buffalo\n");
	exit(0);
}

void	what_map(t_frl *f)
{
	if (f->map == 0)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
																julia");
	else if (f->map == 1)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
															mandelbrot");
	else if (f->map == 2)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
															burning_ship");
	else if (f->map == 3)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
																duobrot");
	else if (f->map == 4)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
																triobrot");
	else if (f->map == 5)
		mlx_string_put(f->mlx_ptr, f->win, 10, 0, 0x00FFFFFF, "fractol: \
																buffalo");
}
