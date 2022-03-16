/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:05:28 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/16 19:16:29 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_list_print(const t_doubly *l)
{
	t_node	*tmp;
	tmp = l->begin;

	while(tmp != NULL)
	{
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
}
