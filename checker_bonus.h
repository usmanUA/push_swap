/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:59 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 17:27:15 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"
#include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
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

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
	t_moves *moves;
	t_list *instructions;
} t_stacks;

int	ft_initializestacks(t_stacks *stacks);
int	ft_stack(int tot, char **argv, t_stack **a);
int	ft_createstack(int tot, t_stack **a, int **c);
int	ft_newstack(t_stack **a, int num);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int	ft_stacksize(t_stack *stack);
int	ft_newstack(t_stack **a, int num);
void	ft_freestack(t_stack *stack);
void	ft_freestacks(t_stacks *stacks);

void	ft_freestr(char **str);

int	*ft_fromvar(char **argv, int *tot);
int	*ft_numsarr(int tot, char **arg);
int	ft_wordcount(char **words);
int	ft_sorted(int *c, int tot);
int	ft_checknumdup(int *arr, int tot);

void	ft_rotate(t_stacks *stacks, int move);
void	ft_rotate_a(t_stacks *stacks);
void	ft_rotate_b(t_stacks *stacks);
void	ft_revrotate(t_stacks *stacks, int move);
void	ft_revrotate_a(t_stacks *stacks);
void	ft_revrotate_b(t_stacks *stacks);
void	ft_swap(t_stacks *stacks, int move);
void	ft_swap_a(t_stacks *stacks);
void	ft_swap_b(t_stacks *stacks);
void    ft_push(t_stacks *stacks, int stack);
void	ft_push_a(t_stacks *stacks);
void	ft_push_b(t_stacks *stacks);

void    ft_sort_two(t_stacks *stacks);
void    ft_sort_three(t_stacks *stacks);
void    ft_sort_four(t_stacks *stacks);
int ft_sort_small(t_stacks *stacks);
void    ft_sort(t_stacks *stacks);
void    ft_findmoves(t_stacks *stacks);
void    ft_get_top_a(t_stacks *stacks, t_stack *tmp_a, int size, int ind);
void    ft_getmoves(t_stacks *stacks, int size, int ind, int stack);
void    ft_savemoves(t_stacks *stacks, int r, int rr, int stack);
void    ft_get_num_b(t_stacks *stacks, int num);
int ft_findindex(t_stack *stack, int num);
void    ft_newnum_b(t_stacks *stacks, t_stack *tmp_b, int num);
void    ft_optimal(t_stacks *stacks, int ind);
void	ft_optimize(t_stacks *stacks);
void    ft_moveoptimal(t_stacks *stacks);
void    ft_moverest(t_stacks *stacks);

void    ft_move_back(t_stacks *stacks);
void    ft_minmax(t_stacks *stacks, int stack);
void    ft_setminmax(t_stacks *stacks, int min, int max, int stack);
void    ft_newmax_a(t_stacks *stacks, t_stack *tmp_a);
void    ft_newmin_a(t_stacks *stacks, t_stack *tmp_a);
void    ft_get_num_a(t_stacks *stacks, t_stack *stack, int num);
void    ft_bringup_a(t_stacks *stacks);


void    ft_displaystacks(t_stacks *stacks); // remove me


#endif
