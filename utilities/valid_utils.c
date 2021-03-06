/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:40 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:19:41 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_duplicate_exist(int *tmp, unsigned int length)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < i)
		{
			if (tmp[i] == tmp[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_index(int **tmp, unsigned int *stack, unsigned int length)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	value;

	i = 0;
	while (i < length)
	{
		value = 0;
		j = 0;
		while (j < length)
		{
			if ((*tmp)[j] < (*tmp)[i])
				value++;
			j++;
		}
		stack[i] = value;
		i++;
	}
	free((*tmp));
	(*tmp) = NULL;
}

int	ft_is_representable(char *str)
{
	int				i;
	unsigned int	length;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[0] == '-' && i == 1)
		return (0);
	length = ft_strlen(str);
	if ((length > 10 && str[0] != '-') || (length > 11 && str[0] == '-'))
		return (0);
	if ((length < 10 && str[0] != '-') || (length < 11 && str[0] == '-'))
		return (1);
	if ((str[0] != '-' && ft_strncmp(str, "2147483647", 10) > 0)
		|| (str[0] == '-' && ft_strncmp(str, "-2147483648", 11) > 0))
		return (0);
	return (1);
}
