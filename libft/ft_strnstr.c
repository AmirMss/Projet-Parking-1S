/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:35:01 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/17 04:49:39 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*tmps1;
	char	*tmps2;
	size_t	tmpn;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			tmpn = n;
			tmps1 = (char *)s1 + 1;
			tmps2 = (char *)s2 + 1;
			while (tmpn-- && *tmps1 && *tmps1 == *tmps2)
			{
				tmps1++;
				tmps2++;
			}
			if (!*tmps2)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
