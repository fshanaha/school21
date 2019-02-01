/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:45:59 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:54:02 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*a;
	unsigned int	c;

	if (!(c = (ft_safelen(s) + 1)))
		return (0);
	if (!(a = (char*)malloc(sizeof(char) * c)))
		return (0);
	a[c-- - 1] = '\0';
	while (c)
	{
		a[c - 1] = (*f)(s[c - 1]);
		c--;
	}
	return (a);
}
