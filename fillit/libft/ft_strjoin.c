/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:53:17 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 20:33:55 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		a;
	size_t		b;
	size_t		n;
	char		*str;

	b = 0;
	a = 0;
	n = 0;
	if (!(s1) || !(s2))
		return (0);
	while (s1[a])
		a++;
	while (s2[b++])
		a++;
	if (!(str = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	a = 0;
	while (s1[a])
		str[n++] = s1[a++];
	a = 0;
	while (s2[a])
		str[n++] = s2[a++];
	str[n] = '\0';
	return (str);
}
