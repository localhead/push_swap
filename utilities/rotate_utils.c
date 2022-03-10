/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:29 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:30 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_to(t_list **stack_a, t_list **stack_b,
								t_list *goal, t_status *status)
{
	while ((*stack_a) != goal && (*stack_b)->value != status->min)
		ft_both_reverse_rotate(stack_a, stack_b);
	while ((*stack_a) != goal)
		ft_reverse_rotate(stack_a, 'a');
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
		ft_status_update(stack_b, status);
	}
}

void	ft_rotate_to(t_list **stack_a, t_list **stack_b,
						t_list *goal, t_status *status)
{
	while ((*stack_a) != goal && (*stack_b)->value != status->min)
		ft_both_rotate(stack_a, stack_b);
	while ((*stack_a) != goal)
		ft_rotate(stack_a, 'a');
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
		ft_status_update(stack_b, status);
	}
}

int	ft_rotate_direction(t_list *stack, t_list *goal)
{
	t_list				*tmp;
	unsigned long long	i;
	unsigned long long	j;

	i = 0;
	j = 0;
	tmp = stack;
	while (tmp != goal)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = stack;
	while (tmp != goal)
	{
		tmp = tmp->prev;
		j++;
	}
	if (i > j)
		return (-1);
	return (1);
}
