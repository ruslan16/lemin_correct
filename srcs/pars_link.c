/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:44:50 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 23:29:16 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

int	will_continue(char **line)
{
	read_line(line);
	if (!ft_strlen(*line))
	{
		free(*line);
		return (0);
	}
	return (1);
}

int	get_index(char *name, t_map *map)
{
	int		i;
	char	**names;

	i = 0;
	names = map->room_names;
	while (names[i])
	{
		if (ft_strequ(names[i], name))
			return (i);
		i++;
	}
	send_error(1);
	return (-1);
}

void		pars_links_t(t_map **map, char *line)
{
	char	**split;
	int		first;
	int		second;

	split = ft_strsplit(line, '-');
	free(line);
	send_error(!split[1] || split[2]);
	first = get_index(split[0], *map);
	second = get_index(split[1], *map);
	(*map)->paths[first][second] = 1;
	(*map)->paths[second][first] = 1;
	free_double(split);
}

void	pars_links(t_map **map, char *str, int *start, int *end)
{
	char	*line;

	send_error(*start == -1 || *end == -1);
	room_list_to_array(map, start, end);
	pars_links_t(map, str);
	while (will_continue(&line))
		pars_links_t(map, line);
}