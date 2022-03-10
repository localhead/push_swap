/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:17 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:17 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_swap(t_list **stack)
{
	if (((((*stack)->prev)->value < ((*stack)->next)->value)
			&& ((*stack)->value < ((*stack)->prev)->value))
		|| (((*stack)->value > ((*stack)->next)->value)
			&& (((*stack)->prev)->value <= ((*stack)->next)->value))
		|| ((((*stack)->prev)->value > (*stack)->value)
			&& ((*stack)->value > ((*stack)->next)->value)))
		return (1);
	return (0);
}

int	ft_is_rotate(t_list **stack)
{
	if ((((*stack)->value > ((*stack)->prev)->value)
			&& (((*stack)->prev)->value >= ((*stack)->next)->value)))
		return (1);
	return (0);
}

int	ft_is_reverse_rotate(t_list **stack)
{
	if (((*stack)->value < ((*stack)->next)->value)
		&& ((*stack)->value > ((*stack)->prev)->value))
		return (1);
	return (0);
}
