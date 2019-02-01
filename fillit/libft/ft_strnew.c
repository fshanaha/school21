/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:50:16 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/07 16:50:17 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (!(ptr = (char*)malloc(size + 1)))
		return (0);
	while (size >= 1)
	{
		ptr[size] = '\0';
		size--;
	}
	ptr[size] = '\0';
	return (ptr);
}
