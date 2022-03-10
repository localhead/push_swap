/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:20:38 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:20:38 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple_sort(t_list **stack)
{
	if (((((*stack)->prev)->value < ((*stack)->next)->value)
			&& ((*stack)->value < ((*stack)->prev)->value))
		|| (((*stack)->value > ((*stack)->next)->value)
			&& (((*stack)->prev)->value <= ((*stack)->next)->value))
		|| ((((*stack)->prev)->value > (*stack)->value)
			&& ((*stack)->value > ((*stack)->next)->value)))
		ft_swap(*stack, 'a');
	if (((*stack)->value > ((*stack)->prev)->value)
		&& (((*stack)->prev)->value >= ((*stack)->next)->value))
		ft_rotate(stack, 'a');
	if (((*stack)->value < ((*stack)->next)->value)
		&& (*stack)->value > ((*stack)->prev)->value)
		ft_reverse_rotate(stack, 'a');
}
