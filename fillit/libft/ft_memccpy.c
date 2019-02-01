/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:19:15 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 20:21:32 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			a;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	a = 0;
	while (a < n)
	{
		dst1[a] = src1[a];
		if (dst1[a] == (unsigned char)c)
			return (&dst1[a + 1]);
		a++;
	}
	return (0);
}
