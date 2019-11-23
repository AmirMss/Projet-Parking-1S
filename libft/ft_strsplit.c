/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 01:10:26 by tbeguin           #+#    #+#             */
/*   Updated: 2018/11/26 10:27:19 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_countword(char const *s, char c)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static unsigned int		ft_lenofword(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char					**ft_strsplit(char const *s, char c)
{
	int		nb_ofwords;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	nb_ofwords = ft_countword(s, c);
	tab = (char **)malloc((nb_ofwords + 1) * sizeof(char*));
	i = 0;
	if (!tab)
		return (NULL);
	while (nb_ofwords--)
	{
		while (*s != '\0' && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, ft_lenofword((char *)s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_lenofword(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
