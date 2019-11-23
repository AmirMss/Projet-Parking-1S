/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:36:42 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/18 19:02:32 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lendigit(int n)
{
	int		len;
	long	tmp;

	tmp = (long)n;
	if (tmp == 0)
		return (1);
	len = 0;
	if (tmp < 0)
	{
		len++;
		tmp = -tmp;
	}
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	tmp;

	tmp = (long)n;
	len = ft_lendigit(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (tmp < 0)
	{
		result[0] = '-';
		tmp = -tmp;
	}
	if (tmp == 0)
		result[0] = '0';
	while (tmp != 0)
	{
		result[len - 1] = (tmp % 10) + '0';
		tmp = tmp / 10;
		len--;
	}
	return (result);
}
