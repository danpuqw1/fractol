/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:59:35 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 12:59:36 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	while (count-- > 0)
		if ((*d++ = *s++) == (char)c)
			return (d);
	return (NULL);
}
