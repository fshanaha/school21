/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:03:53 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:46:16 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a])
	{
		while (haystack[a + b] == needle[b] && haystack[a + b])
			b++;
		if (needle[b] == '\0')
			return ((char*)&haystack[a]);
		b = 0;
		a++;
	}
	return (0);
}
