/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:59 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/06 17:54:01 by uahmed           ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

// typedef struct s_stack_b
// {
// 	int				num;
// 	struct s_stack_b	*next;
// }					t_stack_b;

typedef struct s_moves
{
	int cost;
	int pa;
	int pb;
	int sa;
	int sb;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
} 		t_moves;

typedef struct s_optimal
{
	int cost;
	int pa;
	int pb;
	int sa;
	int sb;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
} 		t_optimal;

typedef struct s_limits
{
	int min_b;
	int max_b;
	int min_a;
	int max_a;
} t_limits;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
	t_moves *moves;
	t_optimal *optimal;
	t_limits *limits;
} t_stacks;

int					ft_createstack(int tot, t_stack *stack, int *c);
int					ft_stack(int tot, char **argv, t_stack **a);
// t_stack				*ft_stacklast(t_stacks *stacks);
// void				ft_stackadd_back(t_stack *stack, t_stack *last);
void				ft_stackadd_front(t_stack *stack, t_stack *new);
t_stack_a				*ft_stacknew(int num);
void				ft_stackclear(t_stack *stack);
size_t				ft_wordcount(char **words);
int					ft_checknumdup(int *arr, int tot);
int					*ft_numsarr(int tot, char **arg, int start);
int					*ft_fromvar(char **argv, int *tot);
int					*ft_arrcpy(int *c, int tot);
void				ft_rotate(t_stacks *stack, int move);
void				ft_revrotate(t_stacks *stack, int move);
void				ft_swap(t_stacks *stack);
void				ft_free(char **s);

#endif
