/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:32:20 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:47:09 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		a;
	char		*str;

	if (!s)
		return (0);
	if ((a = ft_safelen(s)) < (size_t)start + len)
		return (0);
	if (!(str = (char*)malloc(len + 1)))
		return (0);
	a = 0;
	while (a < len)
	{
		str[a] = s[start + a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
