/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:33:28 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/10 15:38:59 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t n;
	size_t a;

	n = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			n++;
			while (s[a] != c && s[a])
				a++;
		}
		while (s[a] == c)
			a++;
	}
	return (n);
}
