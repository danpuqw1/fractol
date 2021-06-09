/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:19:00 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 12:19:01 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_0(void)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * 2);
	if (!(res))
		return (NULL);
	return (ft_strcpy(res, "\0"));
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		sti;
	int		endi;
	int		len;
	int		count;

	if (!(s))
		return (NULL);
	sti = 0;
	len = ft_strlen(s);
	while ((s[sti] == ' ' || s[sti] == '\t' || s[sti] == '\n') && sti <= len)
		sti++;
	if (s[sti] == '\0')
		return (get_0());
	endi = len - 1;
	while ((s[endi] == ' ' || s[endi] == '\t' || s[endi] == '\n') && endi >= 0)
		endi--;
	res = (char*)malloc(sizeof(char) * (endi - sti + 2));
	if (!(res))
		return (NULL);
	count = 0;
	while (sti <= endi)
		res[count++] = s[sti++];
	res[count] = '\0';
	return (res);
}
