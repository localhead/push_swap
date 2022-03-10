/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:18:58 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:46:11 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *error_messege)
{
	write(2, error_messege, ft_strlen(error_messege));
	exit(1);
}

void	ft_error_args(char ****args, int **tmp)
{
	ft_free_args(args);
	free(*tmp);
	ft_error("Error\n");
}
