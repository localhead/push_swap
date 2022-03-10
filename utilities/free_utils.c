/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:06 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:46:15 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_args(char ****args)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((*args)[i])
	{
		j = 0;
		while ((*args)[i][j])
		{
			free((*args)[i][j]);
			j++;
		}
		free((*args)[i]);
		i++;
	}
	free((*args));
	(*args) = NULL;
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = (*stack);
		tmp = tmp->next;
		while (tmp != (*stack))
		{
			tmp = tmp->next;
			free(tmp->prev);
		}
		free(tmp);
		(*stack) = NULL;
	}
}
