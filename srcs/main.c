/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:37:03 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"
#include <unistd.h>

t_list		*new_list(int i)
{
	t_list	*tr;
	int		*hi;

	tr = (t_list *)malloc(sizeof(t_list));
	hi = (int *)malloc(sizeof(int));
	*hi = i;
	tr->content = hi;
	tr->content_size = 0;
	tr->next = NULL;
	return (tr);
}

void		read_line(char **line)
{
	char	*l;

	while (1)
	{
		get_next_line(0, &l);
		if (l[0] != '#' || ft_strequ("##start", l) || ft_strequ("##end", l))
		{
			*line = l;
			ft_putstr(l);
			ft_putchar('\n');
			break ;
		}
		free(l);
	}
}

int			get_ants(void)
{
	char	*line;
	int		tr;

	read_line(&line);
	tr = ft_atoi(line);
	free(line);
	send_error(tr <= 0);
	return (tr);
}

int			main(void)
{
	t_map	*map;
	int		ants;
	int		start;
	int		end;

	ants = get_ants();
	map = NULL;
	start = -1;
	end = -1;
	pars_rooms(&map, &start, &end);
	algo(ants, start, end, map);
	free_map(map);
	return (0);
}
