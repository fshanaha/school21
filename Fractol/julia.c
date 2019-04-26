/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:18:19 by fshanaha          #+#    #+#             */
/*   Updated: 2019/04/01 18:01:03 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static	void		julia_alg2(t_frl *f)
{
	int		i;

	f->buff = (f->x - f->zoom.whalf) / f->zoom.zoom_w + f->zoom.movex;
	while (f->y < f->y_max)
	{
		f->reim.newre = f->buff;
		f->reim.newim = (f->y - f->zoom.hhalf) / f->zoom.zoom_w + f->zoom.movey;
		i = -1;
		while ((f->reim.newre * f->reim.newre + f->reim.newim * f->reim.newim)
												< 4 && ++i < f->maxiterations)
		{
			f->reim.oldre = f->reim.newre;
			f->reim.oldim = f->reim.newim;
			f->reim.newre = f->reim.oldre * f->reim.oldre - f->reim.oldim *
												f->reim.oldim + f->reim.cre;
			f->reim.newim = 2 * f->reim.oldre * f->reim.oldim + f->reim.cim;
		}
		chech_color(i, f);
		f->y++;
	}
}

static	void		*julia_alg(void *fra)
{
	int		buff;
	t_frl	*f;

	f = (t_frl*)fra;
	f->x = -1;
	buff = f->y;
	f->zoom.zoom_h = f->zoom.zoom * HEIGHT * 0.45;
	f->zoom.zoom_w = f->zoom.zoom * WIDTH * 0.45;
	while (++f->x < WIDTH)
	{
		f->y = buff;
		julia_alg2(f);
	}
	return (fra);
}

void				julia(t_frl *f)
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
		pthread_create(&t[i], NULL, julia_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win, f->img.img_ptr, 0, 0);
}
