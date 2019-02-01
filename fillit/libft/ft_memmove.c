/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:45:48 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 20:22:22 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			a;

	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	a = 0;
	if (src < dst)
		while (n > 0)
		{
			dst1[n - 1] = src1[n - 1];
			n--;
		}
	else
		while (a < n)
		{
			dst1[a] = src1[a];
			a++;
		}
	return (dst);
}
