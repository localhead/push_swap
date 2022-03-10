/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:48 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:49 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_list **stack, char stack_name)
{
	if (*stack)
	{
		(*stack) = (*stack)->next;
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse_rotate(t_list **stack, char stack_name)
{
	if (*stack)
	{
		(*stack) = (*stack)->prev;
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_both_rotate(t_list **a, t_list **b)
{
	if (*a)
		(*a) = (*a)->next;
	if (*b)
		(*b) = (*b)->next;
	if (*a || *b)
		write(1, "rr\n", 3);
}

void	ft_both_reverse_rotate(t_list **a, t_list **b)
{
	if (*a)
		(*a) = (*a)->prev;
	if (*b)
		(*b) = (*b)->prev;
	if (*a || *b)
		write(1, "rrr\n", 4);
}
