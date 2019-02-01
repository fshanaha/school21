/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:31:23 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/15 19:27:37 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int num;
	int half;
	int secpow;

	num = 1;
	if (nb == 0 || nb == 1)
		return (nb == 0 ? 0 : 1);
	half = (nb / 2) + 1;
	while (num <= half && num < 46341)
	{
		secpow = num * num;
		if (secpow >= nb)
			return (num - (secpow == nb ? 0 : 1));
		num++;
	}
	return (0);
}
