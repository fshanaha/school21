/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:05:38 by sbrella           #+#    #+#             */
/*   Updated: 2018/11/30 21:17:38 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	if (!(ptr = (char*)malloc(size)))
		return (0);
	while (size >= 1)
	{
		ptr[size - 1] = '\0';
		size--;
	}
	return ((void*)ptr);
}
