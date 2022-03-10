/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:12 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:13 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_rotate_dst(t_list *element, t_list *dst)
{
	int	result;

	result = ((element->value > dst->value)
			&& (dst->index == element->index));
	return (result);
}

int	ft_is_rrotate_dst(t_list *element, t_list *dst)
{
	int	result;

	result = ((element->value < dst->value)
			&& (element->value < (dst->prev)->value)
			&& ((dst->prev)->index == element->index)
			&& (dst->index == element->index));
	return (result);
}

unsigned long long	ft_rotate_count_to_insert(t_list *element, t_list *stack)
{
	unsigned long long	count;

	count = 0;
	while (element->value > stack->value && stack->index == element->index)
	{
		count++;
		stack = stack->next;
	}
	while (element->value < stack->value
		&& (stack->prev)->index == element->index
		&& stack->index == element->index)
	{
		count++;
		stack = stack->prev;
	}
	return (count);
}

void	ft_change_elements_index(t_list *stack)
{
	t_list		*tmp;
	long long	index;

	tmp = stack;
	index = stack->index;
	while (tmp != tmp->prev && (tmp->prev)->index == index)
		tmp = tmp->prev;
	while (tmp->index == index)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}
