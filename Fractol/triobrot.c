/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triobrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:09:40 by fshanaha          #+#    #+#             */
/*   Updated: 2019/03/19 16:52:03 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

static	void		triobrot_alg3(t_frl *f)
{
	f->reim.oldre = f->reim.newre;
	f->reim.oldim = f->reim.newim;
	f->reim.newre = f->reim.oldre * f->reim.oldre * f->reim.oldre *
	f->reim.oldre + f->reim.oldim * f->reim.oldim * f->reim.oldim *
	f->reim.oldim - 6 * f->reim.oldre * f->reim.oldre * f->reim.oldim
	* f->reim.oldim + f->reim.pr;
	f->reim.newim = 4 * f->reim.oldre * f->reim.oldre * f->reim.oldre
	* f->reim.oldim - 4 * f->reim.oldre * f->reim.oldim * f->reim.oldim
	* f->reim.oldim + f->reim.pi;
}

static	void		triobrot_set_0(t_frl *f)
{
	f->reim.newre = 0;
	f->reim.newim = 0;
	f->reim.oldim = 0;
	f->reim.oldre = 0;
}

static	void		triobrot_alg2(t_frl *f)
{
	int		i;

	f->buff = (f->x - f->zoom.whalf) / f->zoom.zoom_w + f->zoom.movex;
	while (f->y < f->y_max)
	{
		f->reim.pr = f->buff;
		f->reim.pi = (f->y - f->zoom.hhalf) / f->zoom.zoom_w + f->zoom.movey;
		triobrot_set_0(f);
		i = -1;
		while ((pow(f->reim.newre, 3) < 250) && (pow(f->reim.newim, 3) < 250) &&
													(i < f->maxiterations))
		{
			triobrot_alg3(f);
			i++;
		}
		chech_color(i, f);
		f->y++;
	}
}

static	void		*triobrot_alg(void *fra)
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
		triobrot_alg2(f);
	}
	return (fra);
}

void				triobrot(t_frl *f)
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
		pthread_create(&t[i], NULL, triobrot_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win, f->img.img_ptr, 0, 0);
}
