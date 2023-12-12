/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:25:03 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 15:28:08 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	int				m_cost;
	int				index;
	struct s_stack	*targ;
	bool			ab_med;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                                 PUSH_SWAP                                  */
/* ************************************************************************** */
int		push_swap(int ac, char **av, t_stack **sta, t_stack **stb);
int		split_free(char **av);
char	**spliter(int *ac, char **av, int *str);
char	**more_than_two(int *ac, char	**av);

/* ************************************************************************** */
/*                              PUSH_SWAP_SORTER                              */
/* ************************************************************************** */
int		mega_sorter(t_stack **sta, t_stack **stb);
int		mega_sorter_decider(t_stack **sta, t_stack **stb);
int		mega_sorter_decider2(t_stack **sta, t_stack **stb);
int		check_sorted(t_stack **st);
void	rotate_min_top(t_stack **sta);

/* ************************************************************************** */
/*                          PUSH_SWAP_SORTER_UTILS                            */
/* ************************************************************************** */
int		find_min(t_stack *st, t_stack **sta);
int		find_max(t_stack *st, t_stack **sta);
int		cost_def_pb(t_stack *sta, t_stack *stb);
int		cost_def_pa(t_stack *sta, t_stack *stb);
int		search_lowcost(t_stack **st);
int		maximum(t_stack **st);
int		minimum(t_stack **st);
void	ft_cost(t_stack *sta, t_stack *stb);
void	sort_threes(t_stack **sta);
t_stack	*find_index(int min, t_stack **stb);
int		def_index(t_stack **st);
void	make_move_pb(t_stack **sta, t_stack **stb);
void	make_move_pa(t_stack **sta, t_stack **stb);
int		both_ab_median(t_stack *ptr, t_stack **sta, t_stack **stb);
int		both_bl_median(t_stack *ptr, t_stack **sta, t_stack **stb);
int		other_cases(t_stack *ptr, t_stack **stc, int x);
int		ft_abab(t_stack *sta, int ac, int bc);
int		ft_baba(t_stack *sta);
int		ft_baababba(t_stack *sta, int ac, int bc);

/* ************************************************************************** */
/*                             PUSH_SWAP_UTILS                                */
/* ************************************************************************** */
void	create_t_sta(int ac, char **nums, t_stack **sta);
void	sort_threes_biggernext(t_stack **sta);
void	minisort(t_stack **sta, t_stack **stb);
void	sort_fours(t_stack **sta, t_stack **stb);

/* ************************************************************************** */
/*                             PUSH_SWAP_ERRORS                               */
/* ************************************************************************** */
int		check_errors(int ac, char **num_list);
int		check_strings(int ac, char **num_list);
int		check_max_min(int ac, char **num_list);
int		check_dups(int ac, char **num_list);

/* ************************************************************************** */
/*                             PUSH_SWAP_LISTS                                */
/* ************************************************************************** */
t_stack	*ft_lstnew_ps(int num);
void	ft_lstadd_back_ps(t_stack **lst, t_stack **new);
void	ft_lstclear_ps(t_stack **lst);
t_stack	*ft_lstlast_ps(t_stack *lst);
int		ft_lstsize_ps(t_stack *lst);

/* ************************************************************************** */
/*                                ft_s SWAP                                   */
/* ************************************************************************** */
int		sa(t_stack **stack_a, int n);
int		sb(t_stack **stack_b, int n);
int		ss(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	   ft_p PUSH                                  */
/* ************************************************************************** */
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	  ft_r ROTATE                                 */
/* ************************************************************************** */
int		ra(t_stack **stack_a, int n);
int		rb(t_stack **stack_b, int n);
int		rr(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	ft_rr REV ROTATE                              */
/* ************************************************************************** */
int		rra(t_stack **stack_a, int n);
int		rrb(t_stack **stack_b, int n);
int		rrr(t_stack **stack_a, t_stack **stack_b);

#endif