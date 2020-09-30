/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_capacity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:25:03 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		convert_content_size(t_list *paths, int ants)
{
	t_list	*i;
	t_list	*c;

	while (ants > 0)
	{
		i = paths;
		while (i)
		{
			ants--;
			c = (t_list *)i->content;
			c->content_size++;
			if (i->next && i->next->content_size >=
			i->content_size + c->content_size)
				break ;
			i = i->next;
		}
	}
}

void		find_path_capacity(t_list *paths, int ants)
{
	t_list	*i;

	convert_content_size(paths, ants);
	i = paths;
	while (i)
	{
		i->content_size = ((t_list *)i->content)->content_size;
		i = i->next;
	}
}
