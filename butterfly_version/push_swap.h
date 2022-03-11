#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include "libft/libft.h"


typedef struct s_node
{
	struct s_node	*next;
	int		value;
}				t_node;


typedef struct s_list
{
	struct s_node	*head;
	int		size;
	int		number_of_operations;
	
}				t_list;

typedef struct	s_parse
{
	char 	**big_str;
	int		*big_array;
	int		size_array;
	
	int		*ind_array;
	int		*sort_ind_array;
}				t_parse;

int	find_min(t_list *list);
int	find_max(t_list *list);
int get_position_of_elem(t_list *list, int value);
int is_nearly_sort(t_list *list);
void triple_sort(t_list *list, int stack_flag);
void move_elem_on_top(t_list *list, int value, int show_flag);
int five_sort_best_strategy(t_list *list_a);
void five_sort(t_list *list_1, t_list *list_2);
void four_sort(t_list *list_1, t_list *list_2);
void less_six_sort(t_list *list_1, t_list *list_2);
void	first_step_of_sort(t_list *list_1, t_list *list_2, \
							int upper_iter_limit, int show_flag);
void	second_step_of_sort(t_list *list_1, t_list *list_2, int show_flag);
int	get_best_lim_part(t_list *list_a, t_list *list_b, int upper_iter_limit);
int	get_optimal_limit(t_list *list_a, t_list *list_b);
void	general_sort(t_list *list_1, t_list *list_2);

static void	swap_one(t_list *list);
static void	push(t_list *list_src, t_list *list_dest);
static void	rotate_one(t_list *list);
static void	rev_rotate_one(t_list *list);
void	sa_sb(t_list *list, int stack_flag, int show_flag);
void	ss(t_list *list_1, t_list *list_2, int show_flag);
void	pa_pb(t_list *list_1, t_list *list_2, int stack_flag, int show_flag);
void	ra_rb(t_list *list, int stack_flag, int show_flag);
void	rr(t_list *list_1, t_list *list_2, int show_flag);
void	rra_rrb(t_list *list, int stack_flag, int show_flag);
void	rrr(t_list *list_1, t_list *list_2, int show_flag);

static void	atoi_checker(char *str, int sign);
int	ft_atoi_ps(char *str);

t_node	*create_elem(int value);
int		list_length(t_list *list);
t_node	*get_last_elem(t_list *list);
void	add_front_list(t_list *list, t_node *elem);
void	add_back_list(t_list *list, t_node *elem);
void	print_list(t_list *list); //qsfasgasb
t_list	*list_init(int size);
t_list	*create_list(int size);
t_list	*create_list(int size);
t_list	*create_list_from_argv(int size, int *sort_ind_array);
void	free_list(t_list *list);
t_list	*copy_list(t_list *list);
int		is_sort(t_list *list);

void	print_error(void);
void	big_char_str_free(char **big_str);
int	word_counter(char **big_str);
void	swap_sort(int *a, int *b);
int	*indices_array_creator(int size_array);
void	dublicate_check(t_parse *parse);
int	*bubble_sort_start(t_parse *parse, int ind_array_flag);
void	bubble_sort_end(t_parse *parse, int ind_array_flag, int	*second_array);
void	bubble_sort_array(t_parse *parse, int ind_array_flag);
void	big_array_creator(t_parse *parse);
void	num_array_dealer(int argc, char **argv, t_parse *parse);


#endif

