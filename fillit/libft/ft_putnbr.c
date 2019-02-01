/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:52:36 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 20:23:02 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recput(int n)
{
	if ((n > -10) && (n < 10))
		ft_putchar((char)(ABS(n)) + '0');
	else
	{
		ft_recput(n / 10);
		ft_recput(n % 10);
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_recput(n);
}
