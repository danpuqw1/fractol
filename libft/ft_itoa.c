/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:35:10 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 14:35:11 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_n(char *res, int i, int cur_len, long n)
{
	int		count_0;

	while (n > 0)
	{
		count_0 = cur_len - ft_numlen(n);
		while (count_0-- > 0)
		{
			res[i++] = '0';
			cur_len--;
		}
		res[i] = n / (ft_pow(10, ft_numlen(n) - 1)) + 48;
		n = n % (ft_pow(10, ft_numlen(n) - 1));
		i++;
		cur_len--;
	}
	return (i);
}

static char	*get_res(char *res, int otr, long n, int len)
{
	int		i;
	int		cur_len;

	i = 0;
	if (otr == 1)
	{
		n *= -1;
		res[0] = '-';
		i++;
	}
	cur_len = len;
	i = convert_n(res, i, cur_len, n);
	if (otr == 1)
		len++;
	while (i < len)
		res[i++] = '0';
	res[i] = '\0';
	return (res);
}

static void	get_min_int(char *res)
{
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	res[11] = '\0';
}

static char	*get_min_0(int i)
{
	char	*res;

	if (i == 0)
	{
		res = (char*)malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';
	}
	if (i == 1)
	{
		res = (char*)malloc(sizeof(char) * 12);
		get_min_int(res);
	}
	if (!(res))
		return (NULL);
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		otr;
	long	a;
	int		len;

	otr = 0;
	len = ft_numlen(n);
	if (n == -2147483648)
		return (get_min_0(1));
	if (n == 0)
		return (get_min_0(0));
	if (n < 0)
		otr = 1;
	if (otr == 1)
		res = (char*)malloc(sizeof(char) * (len + 2));
	else
		res = (char*)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	a = n;
	return (get_res(res, otr, a, len));
}
