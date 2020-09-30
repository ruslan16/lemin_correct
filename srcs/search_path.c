/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:27:13 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

void		push(t_queue *queue, t_list *ta)
{
	ta->next = NULL;
	if (is_empty(queue))
	{
		queue->first = ta;
		queue->last = ta;
	}
	else
	{
		queue->last->next = ta;
		queue->last = ta;
	}
}

void		remove_ste_connections(t_queue *paths, t_map *map, int start,
							int end)
{
	t_list	*ta;
	t_list	*wrapper;

	if (map->paths[start][end])
	{
		ta = NULL;
		ft_lstadd(&ta, new_list(end));
		ft_lstadd(&ta, new_list(start));
		wrapper = (t_list *)malloc(sizeof(t_list));
		wrapper->content = ta;
		wrapper->content_size = 1;
		wrapper->next = NULL;
		map->paths[start][end] = 0;
		map->paths[end][start] = 0;
		push(paths, wrapper);
	}
}

t_queue		*queue(void)
{
	t_queue	*tr;

	tr = (t_queue *)malloc(sizeof(t_queue));
	tr->first = NULL;
	tr->last = NULL;
	return (tr);
}

t_list		*search_path(t_map *map, int start, int end)
{
	t_queue	*paths;
	t_list	*paths_list;
	t_list	*ta;
	int		*room_pointers;

	map->paths[start][start] = 1;
	paths = queue();
	remove_ste_connections(paths, map, start, end);
	room_pointers = (int *)malloc(sizeof(int) * map->num_of_rooms);
	get_room_pointers(room_pointers, map);
	while ((ta = get_augmenting_path(map, start, end, room_pointers))
	!= NULL)
	{
		push(paths, ta);
		remove_visited(map, start);
	}
	free(room_pointers);
	paths_list = peek(paths);
	free(paths);
	return (paths_list);
}

void		algo(int ants, int start, int end, t_map *map)
{
	t_list	*paths;
	t_list	*ant_list;
	int		can_continue;
	int		ants_left;

	if (!ants)
		return ;
	paths = search_path(map, start, end);
	send_error(!paths);
	sort_paths(&paths);
	find_path_capacity(paths, ants);
	ant_list = NULL;
	can_continue = 1;
	ants_left = ants;
	while (can_continue)
	{
		move_ants(&ant_list, map, &can_continue);
		if (ant_list && can_continue)
			ft_putchar('\n');
		can_continue = add_ants(paths, &ant_list, ants, &ants_left)
				|| can_continue;
	}
	ft_lstdel(&paths, &delete_paths);
	ft_lstdel(&ant_list, &delete_info);
}
