/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:42:01 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 21:14:21 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	*get_rooms(int n)
{
	int	*tr;
	int	i;

	tr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		tr[i] = 0;
		i++;
	}
	return (tr);
}

void		room_list_to_array(t_map **map, int *start, int *end)
{
	t_map	*m;
	t_list	*j;
	int		i;

	m = *map;
	m->paths = (int **)malloc(sizeof(int *) * m->num_of_rooms);
	m->room_names = (char **)malloc(sizeof(int *) * (1 + m->num_of_rooms));
	i = 0;
	j = m->room_name_list;
	while (i < m->num_of_rooms)
	{
		m->paths[i] = get_rooms(m->num_of_rooms);
		m->room_names[i] = ft_strdup((char *)j->content);
		j = j->next;
		i++;
	}
	m->room_names[i] = NULL;
	ft_lstdel(&(m->room_name_list), &delete_info);
	m->room_name_list = NULL;
	*start = m->num_of_rooms - (1 + *start);
	*end = m->num_of_rooms - (1 + *end);
}

void	create_start_end(int *start, int *end, int i, int *mode)
{
	if (*mode == 1)
		*start = i;
	else if (*mode == 2)
		*end = i;
	*mode = 0;
}

int	create_room(t_map *map, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	send_error(split == NULL || split[0] == NULL || split[0][0] == 'L');
	send_error(!split[1] || !split[2] || split[3]);
	free(line);
	ft_lstadd(&(map->room_name_list), ft_lstnew(split[0],
											 ft_strlen(split[0]) + 1));
	free_double(split);
	map->num_of_rooms++;
	return (map->num_of_rooms - 1);
}

void	pars_rooms(t_map **map, int *start, int *end)
{
	char	*line;
	int		flag;

	*map = new_map();
	flag = 0;
	while (1)
	{
		read_line(&line);
		if (ft_strchr(line, '-') != NULL)
		{
			pars_links(map, line, start, end);
			break ;
		}
		if (ft_strequ("##start", line))
			flag = free_with_return(line, 1);
		else if (ft_strequ("##end", line))
			flag = free_with_return(line, 2);
		else
			create_start_end(start, end, create_room(*map, line), &flag);
	}
}