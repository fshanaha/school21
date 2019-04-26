/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:29:42 by fshanaha          #+#    #+#             */
/*   Updated: 2019/03/19 16:51:51 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static	void		burning_ship_set_0(t_frl *f)
{
	f->reim.newre = 0;
	f->reim.newim = 0;
	f->reim.oldim = 0;
	f->reim.oldre = 0;
}

static	void		burning_ship_alg2(t_frl *f)
{
	int		i;

	f->buff = (f->x - f->zoom.whalf) / f->zoom.zoom_w + f->zoom.movex;
	while (f->y < f->y_max)
	{
		f->reim.pr = f->buff;
		f->reim.pi = (f->y - f->zoom.hhalf) / f->zoom.zoom_w + f->zoom.movey;
		burning_ship_set_0(f);
		i = -1;
		while ((f->reim.newre * f->reim.newre + f->reim.newim * f->reim.newim)
												< 4 && ++i < f->maxiterations)
		{
			f->reim.oldre = f->reim.newre;
			f->reim.oldim = f->reim.newim;
			f->reim.newre = f->reim.oldre * f->reim.oldre - f->reim.oldim *
								f->reim.oldim + f->reim.cre + f->reim.pr;
			f->reim.newim = fabs(2 * f->reim.oldre * f->reim.oldim)
												+ f->reim.cim + f->reim.pi;
		}
		chech_color(i, f);
		f->y++;
	}
}

static	void		*burning_ship_alg(void *fra)
{
	int		buff;
	t_frl	*f;

	f = (t_frl*)fra;
	f->x = -1;
	buff = f->y;
	f->zoom.zoom_h = (f->zoom.zoom * HEIGHT) * 0.45;
	f->zoom.zoom_w = (f->zoom.zoom * WIDTH) * 0.45;
	while (++f->x < WIDTH)
	{
		f->y = buff;
		burning_ship_alg2(f);
	}
	return (fra);
}

void				burning_ship(t_frl *f)
{
	int			i;
	pthread_t	t[THREAD];
	t_frl		fr[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		ft_memcpy((void*)&fr[i], (void*)f, sizeof(t_frl));
		fr[i].y = THREAD_W * i;
		fr[i].y_max = THREAD_W * (i + 1);
		pthread_create(&t[i], NULL, burning_ship_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win, f->img.img_ptr, 0, 0);
}
