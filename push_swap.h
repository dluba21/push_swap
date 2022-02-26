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
}				t_errors;


t_node *create_elem(long value);
void add_front_list(t_list *list, long value);
t_list *create_list(int size, char **argv, t_errors *error);
int list_length(t_list *list);
int	ft_atoi(char *str, t_errors *error);
#endif

