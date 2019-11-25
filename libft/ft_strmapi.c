/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 00:22:30 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/17 05:56:32 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (s[i] != '\0')
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	return (new);
}
