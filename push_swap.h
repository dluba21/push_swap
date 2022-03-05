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
	
	int		flag;
	int		value;
}				t_node;


typedef struct s_list
{
	struct s_node	*head;
	
	int		size;
	int		min;
	
	int		max;
	int		mid;
	int		next;
	int		flag;
	
	int		number_of_operations; //just for check, delete it
	
}				t_list;

typedef struct	s_parse
{
	char 	**big_str;
	int		*big_array;
	int		size_array;
	
	int		*ind_array;
	int		*sort_ind_array;
}				t_parse;

t_node *create_elem(int value);
int list_length(t_list *list);
t_node *get_last_elem(t_list *list);
void add_front_list(t_list *list, t_node *elem);
void add_back_list(t_list *list, t_node *elemr);
void print_list(t_list *list);
void print_list_and_flag(t_list *list);
void print_list_in_line(t_list *list, int stack_flag);
t_list *create_list_from_argv(int size, int *sort_ind_array);
t_list *list_init(int size);
int is_sort(t_list *list);

void swap_one(t_list *list);
void push(t_list *list_src, t_list *list_dest);
void rotate_one(t_list *list);
void rev_rotate_one(t_list *list);

//void sa(t_list *list);
//void sb(t_list *list);
//void ss(t_list *list_1, t_list *list_2);
//void pa(t_list *list_a, t_list *list_b);
//void pb(t_list *list_a, t_list *list_b);
//void ra(t_list *list);
//void rb(t_list *list);
//void rr(t_list *list_a, t_list *list_b);
//void rra(t_list *list);
//void rrb(t_list *list);
//void rrr(t_list *list_a, t_list *list_b);

void sa_sb(t_list *list, int stack_flag);
void ss(t_list *list_1, t_list *list_2);
void pa_pb(t_list *list_a, t_list *list_b, int stack_flag);
void ra_rb(t_list *list, int stack_flag);
void rr(t_list *list_a, t_list *list_b);
void rra_rrb(t_list *list, int stack_flag);
void rrr(t_list *list_a, t_list *list_b);


int	ft_atoi_ps(char *str);
void print_error(void);
int word_counter(char **big_str);
void	swap_sort(int *a, int *b);
int *indices_array_creator(int size_array);
void dublicate_check(t_parse *parse);
void quick_sort_array(t_parse *parse, int ind_array_flag);
void big_array_creator(t_parse *parse);
void num_array_dealer(int argc, char **argv, t_parse *parse);

#endif

