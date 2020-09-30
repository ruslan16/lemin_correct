/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:00:47 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:00:47 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_list		*get_path(t_map *map, int end, int *room_pointers)
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

void		free_map(t_map *map)
{
	int		i;

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
