/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:54:44 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 20:33:54 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcopy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] && (size > 1))
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	if (size >= 1)
		dst[i] = '\0';
	return (i);
}
