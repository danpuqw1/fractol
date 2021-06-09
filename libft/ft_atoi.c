/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:36:47 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 14:36:48 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		str_skip(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if (str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
				break ;
		}
		i++;
	}
	while (str[i] == '0')
		i++;
	return (i);
}

static size_t	ft_strlen_digit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int		cmp_istr(const char *str1, const char *str2)
{
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen_digit(str1);
	len2 = ft_strlen_digit(str2);
	if (len1 > len2)
		return (1);
	if (len1 < len2)
		return (0);
	if (len1 == len2)
	{
		i = 0;
		while (str1[i] != '\0')
		{
			if (ft_isdigit(str2[i]) == 0)
				return (0);
			if (str1[i] > str2[i])
				return (1);
			if (str1[i] < str2[i])
				return (0);
			i++;
		}
	}
	return (0);
}

static int		check_over(int result, const char *str, int otr)
{
	if (ft_isdigit(*(str)) == 0)
		return (result);
	if (cmp_istr(str, "9223372036854775807") == 1 && otr == 1)
	{
		if (result >= 0)
			return (0);
		else
			return (-1);
	}
	if (cmp_istr(str, "9223372036854775808") == 1 && otr == -1)
	{
		if (result >= 0)
			return (0);
		else
			return (-1);
	}
	return (result);
}

int				ft_atoi(const char *str)
{
	int		result;
	int		otr;
	int		i;

	str += str_skip(str);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	otr = 1;
	if (*str == '-' && ft_isdigit(*(str + 1)) == 1)
	{
		otr = -1;
		str++;
	}
	if (*str == '+')
		str++;
	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	result *= otr;
	result = check_over(result, str, otr);
	return (result);
}
