/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:46 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:46 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_cut_element(t_list **src)
{
	t_list	*element;

	element = (*src);
	if ((*src) != (*src)->next)
	{
		(*src) = (*src)->next;
		((element->prev)->next) = (*src);
		(*src)->prev = (element->prev);
	}
	else
		(*src) = NULL;
}

static void	ft_paste_element(t_list **dst, t_list *element)
{
	if (*dst)
	{
		element->prev = ((*dst)->prev);
		element->next = (*dst);
		((*dst)->prev)->next = element;
		(*dst)->prev = element;
	}
	else
	{
		element->next = element;
		element->prev = element;
	}
	(*dst) = element;
}

void	ft_push(t_list **src, t_list **dst, char dst_name)
{
	t_list	*element;

	if (*src)
	{
		element = (*src);
		ft_cut_element(src);
		ft_paste_element(dst, element);
		write(1, "p", 1);
		write(1, &dst_name, 1);
		write(1, "\n", 1);
	}
}
