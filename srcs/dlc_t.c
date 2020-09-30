/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:14:24 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:17:53 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		delete_list(t_list *list)
{
	if (!list)
		return ;
	delete_list(list->next);
	free(list);
}

t_list		*peek(t_queue *queue)
{
	return (queue->first);
}

int			gfp(int *p)
{
	return (*p);
}

void		delete_paths(void *content, size_t content_size)
{
	t_list	*ts;

	ts = (t_list *)content;
	if (content_size)
		content_size = 0;
	ft_lstdel(&ts, &delete_info);
}

void		delete_info(void *content, size_t content_size)
{
	free(content);
	if (content_size)
		content_size = 0;
}
