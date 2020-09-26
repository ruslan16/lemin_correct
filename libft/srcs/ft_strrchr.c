/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:46:23 by etristan          #+#    #+#             */
/*   Updated: 2020/09/24 14:57:20 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t				i;
	size_t				ln;
	unsigned char		sym;
	unsigned const char	*s;

	i = 0;
	ln = 0;
	if (*str == '\0' && str == 0)
		return (0);
	ln = ft_strlen(str);
	sym = (unsigned char)c;
	s = (unsigned const char *)str;
	while (i <= ln)
	{
		if (s[ln - i] == sym)
			return ((char *)s + (ln - i));
		i++;
	}
	return (0);
}
