/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:15:55 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 15:15:56 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	n = size;
	while (n-- != 0 && *d != '\0')
		++d;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			--n;
		}
		++s;
	}
	*d = '\0';
	return (dlen + (s - src));
}
