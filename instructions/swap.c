/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:52 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:53 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_list *stack, char stack_name)
{
	unsigned int	value;

	if (stack)
	{
		value = stack->value;
		stack->value = (stack->next)->value;
		(stack->next)->value = value;
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_both_swap(t_list **a, t_list **b)
{
	unsigned int	value;

	if (*a)
	{
		value = (*a)->value;
		(*a)->value = ((*a)->next)->value;
		((*a)->next)->value = value;
	}
	if (*b)
	{
		value = (*b)->value;
		(*b)->value = ((*b)->next)->value;
		((*b)->next)->value = value;
	}
	if (*a || *b)
		write(1, "ss\n", 3);
}
