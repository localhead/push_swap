/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:19:21 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:46:25 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned long long	ft_get_args_count(char ***args)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
			j++;
		count += j;
		i++;
	}
	return (count);
}

char	***ft_collect_args(int argc, char **argv)
{
	char			***args;
	int				i;

	args = (char ***)ft_calloc(argc, sizeof(char **));
	if (!args)
		ft_error("Malloc error!\n");
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_split(argv[i + 1], ' ');
		if (!(args[i]))
		{
			ft_free_args(&args);
			ft_error("Memory allocation error!\n");
		}
		if (!(args[i][0]))
		{
			ft_free_args(&args);
			ft_error("Error\n");
		}
		i++;
	}
	return (args);
}

int	*ft_to_int(unsigned long long count, char ***args)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(int) * (count));
	if (!tmp)
		return (NULL);
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_is_representable(args[i][j]))
				ft_error_args(&args, &tmp);
			tmp[k] = ft_atoi(args[i][j]);
			k++;
			j++;
		}
		i++;
	}
	return (tmp);
}

t_list	*ft_parse_args(int argc, char **argv)
{
	char				***args;
	unsigned int		*stack;
	int					*tmp;
	unsigned long long	length;

	args = ft_collect_args(argc, argv);
	length = ft_get_args_count(args);
	stack = malloc(sizeof(unsigned int) * (length));
	if (!stack)
	{
		ft_free_args(&args);
		ft_error("Memory allocation error!\n");
	}
	tmp = ft_to_int(length, args);
	if (!tmp)
	{
		ft_free_args(&args);
		ft_error("Memory allocation error!\n");
	}
	if (ft_duplicate_exist(tmp, length))
		ft_error_args(&args, &tmp);
	ft_free_args(&args);
	ft_index(&tmp, stack, length);
	return (create_stack(stack, length));
}
