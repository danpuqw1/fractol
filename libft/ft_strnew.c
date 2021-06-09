/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:57:02 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 10:57:03 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char*)malloc(size + 1);
	if (!(res))
		return (NULL);
	i = 0;
	while (i < size + 1)
		res[i++] = 0;
	return (res);
}
