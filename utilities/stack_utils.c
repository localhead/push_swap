/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:37 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:37 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_create_element(unsigned int value)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->index = 0;
	element->value = value;
	return (element);
}

static void	ft_add_element_to_stack(t_list **stack, t_list *element)
{
	if ((*stack))
	{
		element->prev = (*stack)->prev;
		((*stack)->prev)->next = element;
		element->next = (*stack);
		(*stack)->prev = element;
	}
	else
	{
		(*stack) = element;
		element->prev = (*stack);
		element->next = (*stack);
	}
}

t_list	*create_stack(unsigned int *array, unsigned int length)
{
	unsigned int	i;
	t_list			*stack;
	t_list			*element;

	i = 0;
	stack = NULL;
	while (i < length)
	{
		element = ft_create_element(array[i]);
		if (!element)
		{
			free(array);
			ft_free_stack(&stack);
			ft_error("Memmory allocation error!");
		}
		ft_add_element_to_stack(&stack, element);
		i++;
	}
	free(array);
	return (stack);
}

unsigned long long	ft_get_list_length(t_list *stack)
{
	unsigned long long	length;
	t_list				*tmp;

	tmp = stack;
	length = 0;
	if (!stack)
		return (length);
	if (tmp != tmp->next)
		tmp = tmp->next;
	length++;
	while (tmp != stack)
	{
		tmp = tmp->next;
		length++;
	}
	return (length);
}
