/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:20:29 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:20:29 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_increase_index(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	if (!stack)
		return ;
	(tmp->index)++;
	tmp = tmp->next;
	while (tmp != stack)
	{
		(tmp->index)++;
		tmp = tmp->next;
	}
}

static void	ft_rotate_to_next_pack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	if (tmp->index == -1 && tmp != tmp->next)
		tmp = tmp->next;
	while (tmp->index == -1 && tmp != (*stack))
		tmp = tmp->next;
	while ((*stack) != tmp)
		ft_rotate(stack, 'a');
}

void	ft_status_update(t_list **stack, t_status *status)
{
	t_list				*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack);
	status->max = (*stack)->value;
	status->min = (*stack)->value;
	if ((*stack)->index == -1)
		return ;
	if (tmp != tmp->next)
		tmp = tmp->next;
	while (tmp->index == (*stack)->index && tmp != (*stack))
	{
		if (tmp->value > status->max)
			status->max = tmp->value;
		if (tmp->value < status->min)
			status->min = tmp->value;
		tmp = tmp->next;
	}
	status->mid = (status->max + status->min) / 2;
}

static void	ft_next_sort_iteration(t_list **stack_a, t_list **stack_b,
									t_status *status)
{
	ft_rotate_to_next_pack(stack_a);
	ft_status_update(stack_a, status);
	if ((*stack_a)->value == status->min)
		(*stack_a)->index = -1;
	else if (((*stack_a)->next)->value == status->min)
	{
		ft_swap(*stack_a, 'a');
		(*stack_a)->index = -1;
	}
	else if ((status->max - status->min) > 3)
		ft_quick_sort(stack_a, stack_b, status);
	else
		ft_merge_sort(stack_a, stack_b, status);
}

void	ft_push_swap_sort(t_list *stack_a, t_list *stack_b)
{
	unsigned long long	length;
	t_status			*status;

	length = ft_get_list_length(stack_a);
	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
	{
		ft_free_stack(&stack_a);
		ft_error("Memmory allocation error!");
	}
	status->min = 0;
	status->max = length - 1;
	if (!ft_is_sorted(stack_a))
	{
		if (length > 6)
			while (!ft_is_sorted(stack_a))
				ft_next_sort_iteration(&stack_a, &stack_b, status);
		else if (length < 4)
			ft_simple_sort(&stack_a);
		else
			ft_merge_sort(&stack_a, &stack_b, status);
	}
	while (stack_a->value != 0)
		ft_rotate(&stack_a, 'a');
	free(status);
}
