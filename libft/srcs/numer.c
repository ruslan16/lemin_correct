/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 22:20:37 by etristan          #+#    #+#             */
/*   Updated: 2020/09/24 14:57:20 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	numer(t_printf *f, va_list ap)
{
	int *address;

	address = (int*)va_arg(ap, int*);
	*address = f->n_print;
}
