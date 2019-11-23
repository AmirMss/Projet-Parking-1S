/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:31:13 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/18 20:05:45 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*tmpb;

	tmpb = b;
	while (n--)
		*tmpb++ = (unsigned char)c;
	return (b);
}
