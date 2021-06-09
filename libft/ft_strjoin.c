/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:03:21 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 12:03:23 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_res(char const *s1, char const *s2, char *res)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		l1;
	int		l2;

	if (!(s1) || !(s2))
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!(res))
		return (NULL);
	return (get_res(s1, s2, res));
}
