/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:59 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/04 19:34:52 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				ind;
	int				steps;
	struct s_stack	*next;
}					t_stack;

void				ft_quicksort(int *c, int start, int end);
int					ft_partition(int *c, int i, int pivot);
void				ft_intswap(int *a, int *b);
int					ft_createstacks(t_stack **stack, int *c, int *sorted, int tot, int b);
int					ft_makestacks(int tot, t_stack **a, t_stack **b, int *c);
int					ft_stack(int tot, t_stack **a, t_stack **b, char **argv);
t_stack				*ft_stacklast(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *last);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack				*ft_stacknew(int num, int tot, int *sorted);
void				ft_stackclear(t_stack **stack);
size_t				ft_wordcount(char **words);
int					ft_checknumdup(int *arr, int tot);
int					*ft_numsarr(int tot, char **arg, int start);
int					*ft_fromvar(char **argv, int *tot);
int					*ft_arrcpy(int *c, int tot);
void				ft_rotate(t_stack **stack);
void				ft_revrotate(t_stack **stack);
void				ft_swap(t_list **stack);
void				ft_push(t_stack **a, t_stack **b);
void				ft_free(char **s);

#endif
