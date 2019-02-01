/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smemmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:20:47 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/24 17:21:52 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_smemmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			a;

	if (dst == NULL || src == NULL)
		return (NULL);
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
