/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:12:01 by etristan          #+#    #+#             */
/*   Updated: 2020/09/24 14:57:20 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cell;

	if ((cell = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		cell->content = NULL;
		cell->content_size = 0;
	}
	else
	{
		if (((cell->content) = ft_memalloc(content_size)) == NULL)
		{
			free(cell);
			return (NULL);
		}
		ft_memcpy((cell->content), content, content_size);
		cell->content_size = content_size;
	}
	cell->next = NULL;
	return (cell);
}
