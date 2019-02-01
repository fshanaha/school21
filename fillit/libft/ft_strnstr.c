/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:48:22 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/08 19:39:49 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] && a < len)
	{
		while ((haystack[a + b] == needle[b]) \
				&& (a + b <= len) && haystack[a + b])
			b++;
		if (needle[b] == '\0')
			return ((char*)&haystack[a]);
		a++;
		b = 0;
	}
	return (0);
}
