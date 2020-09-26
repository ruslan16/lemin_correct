/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:14:24 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 22:45:38 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void	delete_list(t_list *list)
{
	if (!list)
		return ;
	delete_list(list->next);
	free(list);
}

t_list	*get_path(t_map *map, int end, int *room_pointers)
{
	t_list	*path;
	t_list	*wrapper;
	int		c;
	size_t	length;

	path = NULL;
	c = end;
	length = 0;
	while (room_pointers[c] != c)
	{
		map->paths[c][c] = map->paths[c][c] | 2;
		ft_lstadd(&path, new_list(c));
		c = room_pointers[c];
		length++;
	}
	if (c != end)
		ft_lstadd(&path, new_list(c));
	length = c != end ? length + 1 : length;
	if (path == NULL)
		return (NULL);
	wrapper = (t_list *)malloc(sizeof(t_list));
	wrapper->content = path;
	wrapper->content_size = length - 1;
	wrapper->next = NULL;
	return (wrapper);
}

t_list	*peek(t_queue *queue)
{
	return (queue->first);
}

int				gfp(int *p)
{
	return (*p);
}

void		delete_paths(void *content, size_t content_size)
{
	t_list	*ts;

	ts = (t_list *)content;
	content_size = 0;
	ft_lstdel(&ts, &delete_info);
}

void		delete_info(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

void		free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->num_of_rooms)
	{
		free(map->room_names[i]);
		free(map->paths[i]);
		i++;
	}
	free(map->room_names);
	free(map->paths);
	free(map);
}