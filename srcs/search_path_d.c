/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:53:26 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 22:38:24 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_queue	*new_t_queue(void)
{
	t_queue	*tr;

	tr = (t_queue *)malloc(sizeof(t_queue));
	tr->first = NULL;
	tr->last = NULL;
	return (tr);
}

void	iap(t_queue **tv, int s, int *rp, t_map *m)
{
	*tv = new_t_queue();
	push(*tv, new_list(s));
	get_room_pointers(rp, m);
}

t_list	*get_augmenting_path(t_map *map, int start, int end, int *room_pointers)
{
	t_list	*path;
	t_queue	*to_visit;
	t_list	*i;
	int		room;
	t_list	*connecting_rooms;

	iap(&to_visit, start, room_pointers, map);
	while (!is_empty(to_visit))
	{
		room = pop_to_visit(to_visit);
		connecting_rooms = get_connecting_rooms(room, map, end);
		i = connecting_rooms;
		while (i)
		{
			if (gfp((int *)i->content) != end || room_pointers[end] == end)
				room_pointers[gfp((int *)i->content)] = room;
			visit(gfp((int *)i->content), map);
			push(to_visit, new_list(gfp((int *)i->content)));
			i = i->next;
		}
		ft_lstdel(&connecting_rooms, &delete_info);
	}
	path = get_path(map, end, room_pointers);
	free(to_visit);
	return (path);
}

void	get_room_pointers(int *room_pointers, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->num_of_rooms)
	{
		room_pointers[i] = i;
		i++;
	}
}

int		is_empty(t_queue *queue)
{
	return (queue->first == NULL);
}