/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecantu-p <ecantu-p@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:14:49 by ecantu-p          #+#    #+#             */
/*   Updated: 2026/03/14 15:17:11 by ecantu-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "000_libft/libft.h"
# include "001_libftprintf/ft_printf.h"
# include <limits.h>
# include <stdarg.h>

typedef struct s_counters
{
	int					i;
	int					k;
	int					l;
	int					m;
	int					n;
	int					x;
	int					y;
	int					stack_a_limit;
}						t_counters;

typedef struct s_node
{
	char				*data;
	int					key;
	int					move;
	int					value;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct s_node_sol
{
	char				sol;
	int					key;
	int					sol_value;
	int					x;
	int					y;
	int					k;
	int					l;
	int					m;
	int					n;
	struct s_node_sol	*prev;
	struct s_node_sol	*next;
}						t_node_solution;

typedef struct s_linked_list
{
	int					avg;
	int					stack_size;
	int					stdev;
	t_node				*current;
	t_node				*head;
	t_node				*tail;
}						t_link_lst;

typedef struct s_linked_list_sol
{
	char				**p_argv;
	double				steps_limits;
	int					c_d;
	int					cluster_counter;
	int					counter;
	int					input_size;
	int					jumps;
	int					**mtx;
	int					run;
	int					stack_size;
	t_node_solution		*current;
	t_node_solution		*head;
	t_node_solution		*tail;
}						t_link_lst_sol;

typedef t_link_lst		t_stack;
typedef t_link_lst_sol	t_stack_solutions;

typedef struct s_stacks
{
	t_stack				stack_a_r;
	t_stack				stack_a_rr;
	t_stack				stack_b_rk;
	t_stack				stack_b_rl;
	t_stack				stack_b_rm;
	t_stack				stack_b_rn;
}						t_stacks;

// push_swap_advance_rules.c
void					ps_rab(t_stack *a, t_stack *b);
void					ps_rrab(t_stack *a, t_stack *b);

// push_swap_basic_rules.c
void					ps_p(t_stack *stack_dst, t_stack *stack_src,
							char stack_dest_name);
void					ps_r(t_stack *stack, char stack_name);
void					ps_rr(t_stack *stack, char stack_name);
void					ps_s(t_stack *stack, char stack_name);

// push_swap_endroutine.c
void					ps_free(void **ptr);
void					ps_clean(void **ptr, size_t ptr_len);
void					ps_stack_clean(t_stack *stack, void (*del)(void **));
void					ps_endroutine(int argc, t_stack stack_a,
							t_stack stack_b, t_stack_solutions *solutions);

// push_swap_error_check.c
long int				ps_atoli(const char *nptr);
char					**ps_checker(int argc, char *argv[]);
char					**ps_checker_arg(char **p_argv);
int						ps_error(char *str, char **ptr, size_t ptr_len);
void					ps_free_p_argv(int argc, char **p_argv);

// push_swap_error_check_utils.c
int						ps_isduplicate(char *slv[], int size);
int						ps_isint(char *nptr);
int						ps_initialize_p_argv(t_stack_solutions *sol, int argc,
							char **argv);

// push_swap_matrix_solution.c
int						ps_check_solution(t_stack stack_a,
							t_stack_solutions sol);
int						ps_mtx_sol(t_stack_solutions *sol);

// push_swap_printf.c
void					ps_display_values(char *argv[]);
void					ps_printf_both_stacks(t_stack *stack_dst,
							t_stack *stack_src);
void					ps_printf_mtx(int **mtx);
void					ps_printf_solution(t_node_solution *node);
void					ps_printf_stack(t_node *stack);

// push_swap_solutions.c
void					ps_select_solution(t_stack_solutions *stack);
int						ps_isfound_solution(t_counters *count, t_stack *stack_b,
							t_stacks *s);
void					ps_xkl(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol);
void					ps_ymn(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol);

// push_swap_solve_compare.c
int						ps_compare_k_m(int a, t_stack stack_b);
int						ps_compare_k_m_reverse(int a, t_stack stack);
int						ps_compare_l_n(int a, t_stack stack_b);
int						ps_compare_l_n_reverse(int a, t_stack stack);
int						ps_isinstdev(t_node *stack_a, int std);

// push_swap_solve_counters.c
void					ps_advance_solution(t_counters *counters);
void					ps_initialize_counters(t_counters *count);
void					ps_initialize_stacks(t_stacks *s, t_stack *stack_a,
							t_stack *stack_b);
int						ps_solve_counters(t_stacks *s, t_counters *count,
							t_stack_solutions *sol);

// push_swap_solutions_node.c
t_node_solution			*ps_ini_solution_node(t_counters count);
void					ps_reset_key(t_node *stack);
void					ps_reverse_reset_key(t_node *stack);

// push_swap_solutions_stack.c
void					ps_add_tail_solution(t_stack_solutions *stack,
							t_node_solution *node);
void					ps_clean_solution(t_stack_solutions *stack,
							void (*del)(void **));
void					ps_ini_solution_stack(t_stack_solutions *stack,
							t_counters count);
void					ps_initialize_stack_solution(t_stack_solutions *stack);
void					ps_sort_solution(t_stack_solutions *statck);

// push_swap_solve_selection.c
void					ps_solve(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol, t_counters *count);
void					ps_solve_2(t_stack *stack_a);
void					ps_solve_3_asc(t_stack *stack, char stack_name);
void					ps_solve_5(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol, t_counters *count);
void					ps_solve_selection(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol, t_counters *count);

// push_swap_solve_utils_rules.c
int						ps_sort_a_r(t_stack stack);
int						ps_sort_b_r(t_stack stack);
int						ps_sort_a_rr(t_stack stack);
int						ps_sort_b_rr(t_stack stack);

// push_swap_solve_utils_stack_b.c
void					ps_solve_counter_stack_b(t_counters count,
							t_stack *stack_b);
void					ps_solve_return_to_stack_a(t_counters count,
							t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions sol);
void					ps_sol_run(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol);

// push_swap_solve_utils.c
void					ps_solve_3_asc_algorithm(t_stack *stack,
							char stack_name);
void					ps_isrun(t_counters *count, t_stack *stack_b,
							t_stack_solutions *sol, t_stacks *s);
void					ps_solve_stack_a_limit(t_counters *count,
							t_stack_solutions *sol, t_stack *stack_a,
							t_stack *stack_b);
void					ps_solve_stack_a(t_counters count, t_stack *stack_a);
void					ps_solve_stack_b(t_stack *stack_a, t_stack *stack_b,
							t_stack_solutions *sol, t_counters *count);

// push_swap_solve.c
void					ps_ini_sort_1_node(t_stack *stack_dst,
							t_stack *stack_src);
void					ps_ini_sort_1_node_x_y_calc(t_stack *stack, int *x,
							int *y, int j);
void					ps_initialize_ranking(t_node *head,
							t_stack_solutions sol);
void					ps_sol_ini(t_stack *stack_a, t_stack_solutions *sol,
							t_counters *count);

// push_swap_utils.c
size_t					ps_dptrlen(const char **str);
void					ps_initialize_avg_std(t_stack *stack_a,
							t_stack *stack_b, int **mtx);
int						ft_mean(int **mtx, size_t mtx_len);
long long int			ft_pseudo_sqrt(long long int nb);
int						ft_pseudo_stdev_s(int mtx_len, int **mtx, int average);

// push_swap_utils_node.c
void					ps_add_head(t_stack *stack, t_node *node);
void					ps_add_tail(t_stack *stack, t_node *node);
void					ps_node_clean(t_node **node, void (*del)(void **));
t_node					*ps_initalizate_node(int key, char *data);
t_node					*ps_node_last(t_node *list);

// push_swap_utils_stack.c
int						ps_initialize(t_stack *stack, int key, char *data);
void					ps_initialize_stack(t_stack *stack);
t_node					*ps_pop_bottom(t_stack *stack);
t_node					*ps_pop_top(t_stack *stack);
void					ps_stack_push(t_stack *stack, t_node *node);

// push_swap_solve_counters_selection.c
void					ps_select_counters(t_counters *count, t_stack *stack_b,
							t_stacks *s);
void					ps_select_counters_rrb(t_counters *count,
							t_stack stack_b, t_stacks *s);
#endif
