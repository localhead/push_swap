/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:34 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:35 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->value != 0)
		tmp = tmp->next;
	stack = tmp;
	while (tmp->value < (tmp->next)->value)
		tmp = tmp->next;
	if ((tmp->next)->value != 0)
		return (0);
	return (1);
}
