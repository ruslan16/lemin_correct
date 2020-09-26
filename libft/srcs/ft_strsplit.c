/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:33:22 by etristan          #+#    #+#             */
/*   Updated: 2020/09/24 14:57:20 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	st;
	size_t	wd;

	if (s == 0 || ((str = (char **)
					malloc(sizeof(char *) * (ft_wdc(s, c) + 1))) == 0))
		return (NULL);
	i = 0;
	wd = 0;
	while (ft_strlen(s) > i)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		st = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if ((i - st) > 0)
		{
			str[wd] = ft_strsub(s, st, i - st);
			wd++;
		}
	}
	str[wd] = 0;
	return (str);
}
