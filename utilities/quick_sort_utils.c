/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:26 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:27 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_last_less_element(t_list **stack, t_status *status)
{
	t_list	*tmp;
	t_list	*last_to_push;

	if ((*stack) == NULL)
		return (NULL);
	tmp = (*stack);
	last_to_push = NULL;
	if ((*stack)->value <= status->mid)
		last_to_push = (*stack);
	if (tmp != tmp->next)
		tmp = tmp->next;
	while ((*stack)->index == tmp->index && (*stack) != tmp)
	{
		if (tmp->value <= status->mid)
			last_to_push = tmp;
		tmp = tmp->next;
	}
	return (last_to_push);
}

t_list	*ft_last_greater_element(t_list **stack, t_status *status)
{
	t_list	*tmp;
	t_list	*last_to_push;

	if ((*stack) == NULL)
		return (NULL);
	tmp = (*stack);
	last_to_push = NULL;
	if ((*stack)->value > status->mid)
		last_to_push = (*stack);
	if (tmp != tmp->next)
		tmp = tmp->next;
	while ((*stack) != tmp)
	{
		if (tmp->value > status->mid)
			last_to_push = tmp;
		tmp = tmp->next;
	}
	return (last_to_push);
}

void	ft_push_less(t_list **stack_src, t_list **stack_dst, t_status *status)
{
	t_list	*tmp;
	t_list	*last_to_push;

	while ((*stack_src)->value <= status->mid)
		ft_push(stack_src, stack_dst, 'b');
	tmp = (*stack_src);
	last_to_push = ft_last_less_element(stack_src, status);
	if ((*stack_src) != (*stack_src)->next
		&& (*stack_src)->index == ((*stack_src)->next)->index && last_to_push)
		ft_rotate(stack_src, 'a');
	while ((*stack_src) != tmp && (*stack_src)->index == tmp->index
		&& last_to_push && (*stack_src) != last_to_push)
	{
		if ((*stack_src)->value <= status->mid)
			ft_push(stack_src, stack_dst, 'b');
		else
			ft_rotate(stack_src, 'a');
	}
	if (last_to_push)
		ft_push(stack_src, stack_dst, 'b');
}

void	ft_push_greater(t_list **stack_src, t_list **stack_dst,
						t_status *status)
{
	t_list	*tmp;
	t_list	*last_to_push;

	while ((*stack_src)->value > status->mid)
		ft_push(stack_src, stack_dst, 'a');
	tmp = (*stack_src);
	last_to_push = ft_last_greater_element(stack_src, status);
	if ((*stack_src) != (*stack_src)->next && last_to_push)
		ft_rotate(stack_src, 'b');
	while ((*stack_src) != tmp && last_to_push && (*stack_src) != last_to_push)
	{
		if ((*stack_src)->value > status->mid)
			ft_push(stack_src, stack_dst, 'a');
		else
			ft_rotate(stack_src, 'b');
	}
	if (last_to_push && (*stack_src) == last_to_push)
		ft_push(stack_src, stack_dst, 'a');
}
