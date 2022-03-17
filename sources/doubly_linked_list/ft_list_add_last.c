/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:00:46 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 14:58:03 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_parse.h"

void	ft_list_add_last(t_circular *l, char *val)
{
	t_cmd	*new;

	new = ft_cmd_create(val);
	new->prev = l->tail;
	if(ft_list_is_empty(l))
		l->head = new;
	else
		l->tail->next = new;
	l->tail = new;
	l->size++;
}
