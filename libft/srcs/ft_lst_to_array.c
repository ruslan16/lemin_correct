/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:47:12 by sirvin            #+#    #+#             */
/*   Updated: 2020/09/26 23:47:12 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lst_to_array(t_list *list, int *size)
{
	int		i;
	t_list	*l;
	t_list	**tr;

	*size = ft_get_lst_size(list);
	tr = (t_list **)malloc(sizeof(t_list *) * (*size));
	if (tr == NULL)
		return (NULL);
	l = list;
	i = 0;
	while (l)
	{
		tr[i] = l;
		i++;
		l = l->next;
	}
	return (tr);
}
