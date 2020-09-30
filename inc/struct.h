/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:34:40 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 20:34:57 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include "lemin.h"

typedef struct	s_map
{
	int			**paths;
	int			num_of_rooms;
	char		**room_names;
	t_list		*room_name_list;
}				t_map;

typedef struct	s_queue
{
	t_list		*first;
	t_list		*last;
}				t_queue;

typedef struct	s_ant
{
	int			n;
	t_list		*path;
}				t_ant;

#endif
