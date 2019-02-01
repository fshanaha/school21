/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:47:36 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 17:13:21 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strminend(const char *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	while ((*str == ' ' || *str == '\t' || \
				*str == '\n' || *str == '\0') && len > 0)
	{
		str--;
		if (*(str + 1) == '\0')
			continue;
		len--;
	}
	return (len + 1);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	c;
	char	*a;

	len = 0;
	if (!(s))
		return (0);
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len++;
	}
	c = ft_strminend(&s[len]);
	if (!(a = (char*)malloc(sizeof(char) * c)))
		return (0);
	a[c-- - 1] = '\0';
	while (c >= 1)
	{
		a[c - 1] = s[len + c - 1];
		c--;
	}
	a[c] = s[len + c];
	return (a);
}
