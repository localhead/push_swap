/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:20:35 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:20:35 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_first_greater_element(t_list *stack,
											unsigned long long mid)
{
	while (stack->value <= mid)
		stack = stack->next;
	return (stack);
}

static void	ft_comeback_to(t_list **stack_a, t_list *goal,
							t_list **stack_b, t_status *status)
{
	if ((goal->prev)->index != -1)
		return ;
	if (ft_rotate_direction((*stack_a), goal) == 1)
		ft_rotate_to(stack_a, stack_b, goal, status);
	else
		ft_reverse_rotate_to(stack_a, stack_b, goal, status);
}

static void	ft_next_sort_iteration(t_list **stack_b, t_list **stack_a,
									t_status *status)
{
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (((*stack_b)->next)->value == status->min)
	{
		ft_swap((*stack_b), 'b');
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if ((status->max - status->min) < 50)
	{
		ft_increase_index((*stack_b));
		ft_insert_sort(stack_b, stack_a, 'a');
	}
	else
	{
		ft_increase_index((*stack_b));
		ft_push_greater(stack_b, stack_a, status);
	}
}

void	ft_quick_sort(t_list **stack_a, t_list **stack_b, t_status *status)
{
	t_list	*great_half_start;

	great_half_start = ft_first_greater_element(*stack_a, status->mid);
	ft_push_less(stack_a, stack_b, status);
	ft_status_update(stack_b, status);
	ft_comeback_to(stack_a, great_half_start, stack_b, status);
	while ((*stack_b))
	{
		ft_next_sort_iteration(stack_b, stack_a, status);
		ft_status_update(stack_b, status);
	}
}
