/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:53:56 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 18:43:09 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*a;
	int			count;
	long int	c;

	c = (long int)n;
	count = ft_countsim(n);
	if (!(a = (char*)malloc(sizeof(char) * count)))
		return (0);
	if (n < 0)
	{
		a[0] = '-';
		c = -c;
	}
	a[count - 1] = '\0';
	count--;
	while (c / 10)
	{
		a[count - 1] = ((char)(c % 10) + '0');
		c = c / 10;
		count--;
	}
	a[count - 1] = ((char)(c) + '0');
	return (a);
}
