/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:58:58 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/30 17:04:10 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lemin.h"

t_map	*new_map(void)
{
	t_map	*tm;

	tm = (t_map *)malloc(sizeof(t_map));
	tm->paths = NULL;
	tm->num_of_rooms = 0;
	tm->room_names = NULL;
	tm->room_name_list = NULL;
	return (tm);
}

int		free_with_return(char *str, int i)
{
	free(str);
	return (i);
}

void	send_error(int b)
{
	if (b)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
