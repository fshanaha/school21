/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:49:38 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:49:48 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && (len > 0))
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while ((len > 0))
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
