/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:20:05 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:20:06 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate_stacks_to_push(t_list **src, t_list **dst,
										t_list *element)
{
	if (!(*src) || !element)
		return ;
	if (ft_rotate_direction((*src), element) == -1)
	{
		while ((*src) != element && ft_is_rrotate_dst(element, (*dst)))
			ft_both_reverse_rotate(src, dst);
		while ((*src) != element)
			ft_reverse_rotate(src, 'b');
	}
	else
	{
		while ((*src) != element
			&& ft_is_rotate_dst(element, (*dst)))
			ft_both_rotate(src, dst);
		while ((*src) != element)
			ft_rotate(src, 'b');
	}
	while (ft_is_rotate_dst(element, (*dst)))
		ft_rotate(dst, 'a');
	while (ft_is_rrotate_dst(element, (*dst)))
		ft_reverse_rotate(dst, 'a');
}

static t_list	*ft_get_next_element(t_list **src, unsigned long long length,
										t_list **dst)
{
	t_list				*tmp;
	t_list				*next;
	unsigned long long	steps;
	unsigned long long	steps_src;
	unsigned long long	steps_min;

	steps_min = ft_rotate_count_to_insert(*src, *dst);
	next = (*src);
	tmp = (*src)->next;
	steps_src = 1;
	while (tmp != *src)
	{
		steps = steps_src;
		if (steps_src > length / 2)
			steps = length - steps_src;
		steps += ft_rotate_count_to_insert(tmp, *dst);
		if (steps < steps_min)
		{
			steps_min = steps;
			next = tmp;
		}
		tmp = tmp->next;
		steps_src++;
	}
	return (next);
}

void	ft_insert_sort(t_list **src, t_list **dst, char stack_name)
{
	unsigned long long	length;
	t_list				*next;

	if (!(*src))
		return ;
	ft_push(src, dst, stack_name);
	length = ft_get_list_length(*src);
	while (*src)
	{
		next = ft_get_next_element(src, length, dst);
		ft_rotate_stacks_to_push(src, dst, next);
		ft_push(src, dst, 'a');
		length--;
	}
	ft_change_elements_index(*dst);
}
