/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:08:09 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 20:15:15 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	l;
	size_t	len1;

	if (s)
	{
		l = ft_strlen(s);
		len1 = 0;
		if (s)
		{
			while (s[len1] == ' ' || s[len1] == '\n' || s[len1] == '\t')
				len1++;
			while (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t')
				l--;
			if (l == 0)
				str = ft_strsub(s, 0, 0);
			else
				str = ft_strsub(s, len1, l - len1);
			return (str);
		}
		return (0x0);
	}
	return (0x0);
}
