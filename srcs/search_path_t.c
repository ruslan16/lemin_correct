/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:01:29 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		remove_visited(t_map *map, int start)
{
	int		i;

	i = 0;
	while (i < map->num_of_rooms)
	{
		if (i != start)
			map->paths[i][i] = map->paths[i][i] & 2;
		i++;
	}
}

void		visit(int visiting, t_map *map)
{
	map->paths[visiting][visiting] = map->paths[visiting][visiting] | 1;
}

t_list		*get_connecting_rooms(int visiting, t_map *map, int end)
{
	t_list	*room_list;
	int		i;

	if (visiting == end)
		return (NULL);
	room_list = NULL;
	i = 0;
	while (i < map->num_of_rooms)
	{
		if (map->paths[visiting][i] && i != visiting &&
			(!map->paths[i][i] || i == end))
		{
			map->paths[i][i] = map->paths[i][i] | 1;
			ft_lstadd(&room_list, new_list(i));
		}
		i++;
	}
	return (room_list);
}

t_list		*pop(t_queue *queue)
{
	t_list	*tr;

	if (is_empty(queue))
		return (NULL);
	tr = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	return (tr);
}

int			pop_to_visit(t_queue *to_visit)
{
	t_list	*val;
	int		tr;

	val = pop(to_visit);
	tr = gfp((int *)val->content);
	free(val->content);
	free(val);
	return (tr);
}
