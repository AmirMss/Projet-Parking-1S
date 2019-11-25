/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:44 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/18 20:04:54 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*edst;
	const char	*esrc;

	edst = dst;
	esrc = src;
	while (n--)
		*edst++ = *esrc++;
	return (dst);
}
