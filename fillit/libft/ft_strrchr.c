/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:49:20 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:49:22 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*str;

	str = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] == (char)c)
			str = (char*)&s[a];
		a++;
	}
	if (c == 0)
		return ((char*)&s[a]);
	return (str);
}
