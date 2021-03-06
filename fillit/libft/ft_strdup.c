/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:31:23 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/08 21:03:03 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		a;
	char	*b;

	a = ft_strlen(s1) + 1;
	if (!(b = (char*)malloc(a)))
		return (0);
	b[a--] = '\0';
	while (a >= 0)
	{
		b[a] = s1[a];
		a--;
	}
	return (b);
}
