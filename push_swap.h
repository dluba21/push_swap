#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	
	int		value;
	
	long		score;
}				t_node;

typedef struct s_list
{
	struct s_node	*head;
	int				size;
		
}				t_list;

typedef struct s_errors
{
	int atoi_flag;
	int list_create_flag;
}				t_errors;


t_node *create_elem(int value);
int list_length(t_list *list);
t_node *get_last_elem(t_list *list);
void add_front_list(t_list *list, t_node *elem, t_errors *error);
void add_back_list(t_list *list, t_node *elem, t_errors *error);
void print_list(t_list *list);
t_list *create_list(int size, char **argv, t_errors *error);
int is_sort(t_list *list);


int	ft_atoi(char *str, t_errors *error);
#endif

