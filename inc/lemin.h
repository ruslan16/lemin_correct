/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:32:52 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 23:42:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEMIN_H
# define LEM_IN_LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "struct.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/s_prft.h"
# include <unistd.h>
# include <stdlib.h>

void			read_line(char **line);
void			pars_rooms(t_map **map, int *start, int *end);
t_list			*new_list(int i);
void			room_list_to_array(t_map **map, int *start, int *end);
void			pars_links(t_map **map, char *str, int *start, int *end);

void			algo(int ants, int start, int end, t_map *map);
t_list			*search_path(t_map *map, int start, int end);
int				is_empty(t_queue *queue);
void			get_room_pointers(int *room_pointers, t_map *map);
void			push(t_queue *queue, t_list *ta);
t_list			*get_augmenting_path(t_map *map, int start, int end,
							int *room_pointers);
int				pop_to_visit(t_queue *to_visit);
int				gfp(int *p);
t_list			*get_connecting_rooms(int visiting, t_map *map, int end);
void			visit(int visiting, t_map *map);
void			remove_visited(t_map *map, int start);
t_list			*peek(t_queue *queue);

void			sort_paths(t_list **paths);
void			find_path_capacity(t_list *paths, int ants);

void			move_ants(t_list **ants, t_map *map, int *can_continue);
void			print_ant(t_ant *ant, t_map *map);
int				add_ants(t_list *paths, t_list **ant_list,
				int ants, int *ants_left);

void			free_double(char **str);
int				will_continue(char **line);
void			send_error(int b);
int				free_with_return(char *str, int i);
t_map			*new_map(void);
void			delete_info(void *content, size_t content_size);
void			free_map(t_map *map);
void			delete_paths(void *content, size_t content_size);
t_list			*get_path(t_map *map, int end, int *room_pointers);
void			delete_list(t_list *list);

#endif
