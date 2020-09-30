/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:26:10 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int			add_ants(t_list *paths, t_list **ant_list, int ants, int *ants_left)
{
	t_list	*i;
	t_ant	*ta;
	t_list	*tal;
	int		tr;

	if (*ants_left < 1)
		return (0);
	i = paths;
	tr = 0;
	while (i && i->content_size && *ants_left >= 1)
	{
		ta = (t_ant *)malloc(sizeof(t_ant));
		ta->path = (t_list *)i->content;
		ta->n = (ants - *ants_left) + 1;
		tal = (t_list *)malloc(sizeof(t_list));
		tal->content = ta;
		tal->content_size = sizeof(ta);
		ft_lstadd(ant_list, tal);
		(*ants_left)--;
		tr = 1;
		i->content_size--;
		i = i->next;
	}
	return (tr);
}

void		print_ant(t_ant *ant, t_map *map)
{
	int		n;
	int		*room_pointer;
	char	*name;

	n = ant->n;
	room_pointer = (int *)ant->path->content;
	name = map->room_names[*room_pointer];
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void		move_ants(t_list **ants, t_map *map, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = *ants;
	*can_continue = 0;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path->next)
		{
			*can_continue = 1;
			current->path = current->path->next;
			print_ant(current, map);
		}
		i = i->next;
	}
}
