/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:15:50 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 14:15:51 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_tmp;

	s_tmp = s;
	while (n-- > 0)
	{
		if (*s_tmp == (unsigned char)c)
			return ((void*)s_tmp);
		s_tmp++;
	}
	return (NULL);
}
