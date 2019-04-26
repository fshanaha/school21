/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:19:27 by fshanaha          #+#    #+#             */
/*   Updated: 2019/04/05 17:42:38 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int			ft_mouse_deal(int key, int x, int y, t_frl *f)
{
	if (key == 5 && f->zoom.zoomiter < 310)
	{
		f->zoom.zoom *= pow(1.05, 2);
		f->zoom.movey += ((y - f->zoom.whalf) / 3500.0 / f->zoom.zoom / 1.5);
		f->zoom.movex += ((x - f->zoom.hhalf) / 3500.0 / f->zoom.zoom / 1.5);
		f->zoom.zoomiter++;
	}
	else if (key == 4 && f->zoom.zoomiter >= 0)
	{
		f->zoom.zoom /= pow(1.05, 2);
		f->zoom.movey -= ((y - f->zoom.whalf) / 3500.0 / f->zoom.zoom / 1.5);
		f->zoom.movex -= ((x - f->zoom.hhalf) / 3500.0 / f->zoom.zoom / 1.5);
		f->zoom.zoomiter--;
	}
	make_map(f);
	return (0);
}

void		shift_key2(int key, t_frl *f)
{
	if (key == 15 && f->color.r >= 0 && f->color.r <= 250)
		f->color.r += (f->color.r == 250) ? 4 : 5;
	else if (key == 14 && f->color.r >= 5 && f->color.g <= 255)
		f->color.r -= 5;
	if (key == 5 && f->color.g >= 0 && f->color.g <= 250)
		f->color.g += (f->color.g == 250) ? 4 : 5;
	else if (key == 3 && f->color.g >= 5 && f->color.g <= 255)
		f->color.g -= 5;
	if (key == 11 && f->color.b >= 0 && f->color.b <= 250)
		f->color.b += (f->color.b == 250) ? 4 : 5;
	else if (key == 9 && f->color.b >= 5 && f->color.b <= 255)
		f->color.b -= 5;
	else if (key == 8)
		f->color.flag ^= 1;
	else if (key == 6)
	{
		f->color.r = 10;
		f->color.g = 0;
		f->color.b = 0;
	}
	make_map(f);
}

void		settings(int key, t_frl *f)
{
	if (key == 121 && f->maxiterations > 5)
		f->maxiterations -= 5;
	else if (key == 116)
		f->maxiterations += 5;
	else if (key == 115 && f->map < 5)
		f->map++;
	else if (key == 119 && f->map > 0)
		f->map--;
}

void		shift_key(int key, t_frl *f)
{
	if (key == 126)
		f->zoom.movey -= 0.01 / f->zoom.zoom;
	else if (key == 125)
		f->zoom.movey += 0.01 / f->zoom.zoom;
	else if (key == 123)
		f->zoom.movex -= 0.01 / f->zoom.zoom;
	else if (key == 124)
		f->zoom.movex += 0.01 / f->zoom.zoom;
	else if ((key == 78 || key == 27) && f->zoom.zoomiter >= 0)
	{
		f->zoom.zoom -= 0.1;
		f->zoom.zoomiter--;
	}
	else if ((key == 69 || key == 24))
	{
		f->zoom.zoom += 0.1;
		f->zoom.zoomiter++;
	}
	else
		settings(key, f);
	make_map(f);
}

int			ft_deal(int key, t_frl *f)
{
	if (key == 53)
		exit(0);
	else if ((key >= 69 && key <= 126)
		|| key == 27 || key == 24)
		shift_key(key, f);
	else if (key >= 3 && key <= 15)
		shift_key2(key, f);
	else if (key == 48)
	{
		params(f);
		make_map(f);
	}
	else if (key == 49)
		f->mouse.j_mouse ^= 1;
	return (0);
}
