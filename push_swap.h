/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:48:28 by mbagg             #+#    #+#             */
/*   Updated: 2022/03/10 18:48:28 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	unsigned int		value;
	struct s_stack		*prev;
	struct s_stack		*next;
	long long			index;
}				t_list;

typedef struct s_status
{
	unsigned long long	max;
	unsigned long long	mid;
	unsigned long long	min;
}				t_status;

void				ft_push_swap_sort(t_list *stack_a, t_list *stack_b);

int					ft_is_representable(char *str);

t_list				*ft_parse_args(int argc, char **argv);

unsigned long long	ft_get_args_count(char ***args);
char				***ft_collect_args(int argc, char **argv);
int					*ft_to_int(unsigned long long count, char ***args);

t_list				*create_stack(unsigned int *stack_a, unsigned int length);
int					ft_is_sorted(t_list *stack);
unsigned long long	ft_get_list_length(t_list *stack);

void				ft_free_stack_and_status(t_list *stack, t_status *status);

void				ft_free_args(char ****args);

void				ft_free_stack(t_list **stack);

void				ft_error_args(char ****args, int **tmp);

void				ft_simple_sort(t_list **stack);

void				ft_quick_sort(t_list **stack_a, t_list **stack_b,
						t_status *status);

void				ft_merge_sort(t_list **stack_a, t_list **stack_b,
						t_status *status);

void				ft_error(char *error_messege);
int					ft_duplicate_exist(int *tmp, unsigned int length);

void				ft_index(int **tmp, unsigned int *stack,
						unsigned int length);

void				ft_increase_index(t_list *stack);

void				ft_insert_sort(t_list **src, t_list **dst,
						char stack_name);

void				ft_status_update(t_list **stack, t_status *status);

int					ft_rotate_direction(t_list *stack, t_list *goal);

void				ft_rotate_to(t_list **stack_a, t_list **stack_b,
						t_list *goal, t_status *status);

void				ft_reverse_rotate_to(t_list **stack_a, t_list **stack_b,
						t_list *goal, t_status *status);

t_list				*ft_last_less_element(t_list **stack, t_status *status);
t_list				*ft_last_greater_element(t_list **stack, t_status *status);

void				ft_push_less(t_list **stack_src, t_list **stack_dst,
						t_status *status);

void				ft_push_greater(t_list **stack_src, t_list **stack_dst,
						t_status *status);

int					ft_is_rotate_dst(t_list *element, t_list *dst);
int					ft_is_rrotate_dst(t_list *element, t_list *dst);
unsigned long long	ft_rotate_count_to_insert(t_list *element, t_list *dst);
void				ft_change_elements_index(t_list *stack);

int					ft_is_swap(t_list **stack);
int					ft_is_rotate(t_list **stack);
int					ft_is_reverse_rotate(t_list **stack);

void				ft_swap(t_list *stack, char stack_name);
void				ft_both_swap(t_list **a, t_list **b);
void				ft_rotate(t_list **stack, char stack_name);
void				ft_both_rotate(t_list **a, t_list **b);
void				ft_reverse_rotate(t_list **stack, char stack_name);
void				ft_both_reverse_rotate(t_list **a, t_list **b);
void				ft_push(t_list **src, t_list **dst, char dst_name);

#endif
