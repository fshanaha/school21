/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:21:01 by fshanaha          #+#    #+#             */
/*   Updated: 2019/03/18 18:59:05 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int		move_julia(int x, int y, t_frl *f)
{
	if (f->mouse.j_mouse == 0 && x <= WIDTH && x >= 0 && y <= HEIGHT &&
												y >= 0 && f->map == 0)
	{
		f->reim.cre = (x - f->zoom.whalf) * 0.0009;
		f->reim.cim = (y - f->zoom.hhalf) * 0.0009;
		make_map(f);
	}
	return (0);
}
