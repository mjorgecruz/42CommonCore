/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:25:03 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 16:04:20 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int		split_free_bonus(char **av);
char	**spliter_bonus(int *ac, char **av, int *str);
int		mega_checker(t_stack **sta, t_stack **stb, int ac);
/* ************************************************************************** */
/*                              PUSH_SWAP_SORTER                              */
/* ************************************************************************** */
int		check_sorted_bonus(t_stack **st);

/* ************************************************************************** */
/*                             PUSH_SWAP_UTILS                                */
/* ************************************************************************** */
void	create_t_sta_bonus(int ac, char **nums, t_stack **sta);
char	**more_than_two_bonus(int *ac, char **av);
int		checker(int ac, char **splited, t_stack **sta, t_stack **stb);

/* ************************************************************************** */
/*                             PUSH_SWAP_ERRORS                               */
/* ************************************************************************** */
int		check_errors_bonus(int ac, char **num_list);
int		check_strings_bonus(int ac, char **num_list);
int		check_max_min_bonus(int ac, char **num_list);
int		check_dups_bonus(int ac, char **num_list);
int		prepare_str_bonus(char *str);

/* ************************************************************************** */
/*                             PUSH_SWAP_LISTS                                */
/* ************************************************************************** */
t_stack	*ft_lstnew_ps_bonus(int num);
void	ft_lstadd_back_ps_bonus(t_stack **lst, t_stack **new);
void	ft_lstclear_ps_bonus(t_stack **lst);
t_stack	*ft_lstlast_ps_bonus(t_stack *lst);
int		ft_lstsize_ps_bonus(t_stack *lst);

/* ************************************************************************** */
/*                                ft_s SWAP                                   */
/* ************************************************************************** */
int		sa_bonus(t_stack **stack_a);
int		sb_bonus(t_stack **stack_b);
int		ss_bonus(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	   ft_p PUSH                                  */
/* ************************************************************************** */
int		pa_bonus(t_stack **stack_a, t_stack **stack_b);
int		pb_bonus(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	  ft_r ROTATE                                 */
/* ************************************************************************** */
int		ra_bonus(t_stack **stack_a);
int		rb_bonus(t_stack **stack_b);
int		rr_bonus(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                             	ft_rr REV ROTATE                              */
/* ************************************************************************** */
int		rra_bonus(t_stack **stack_a);
int		rrb_bonus(t_stack **stack_b);
int		rrr_bonus(t_stack **stack_a, t_stack **stack_b);

#endif