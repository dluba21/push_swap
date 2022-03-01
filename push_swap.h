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
	
	long		score;
}				t_node;

typedef struct s_list
{
	struct s_node	*head;
	int				size;
		
}				t_list;

t_node *create_elem(int value);
int list_length(t_list *list);
t_node *get_last_elem(t_list *list);
void add_front_list(t_list *list, t_node *elem);
void add_back_list(t_list *list, t_node *elemr);
void print_list(t_list *list);
t_list *create_list(int size, char **argv);
int is_sort(t_list *list);

void swap_one(t_list *list);
void swap_both(t_list *list_1, t_list *list_2);
void push(t_list *list_src, t_list *list_dest);
void rotate_one(t_list *list);
void rotate_both(t_list *list_1, t_list *list_2);
void rev_rotate_one(t_list *list); //ra rb
void rev_rotate_both(t_list *list_1, t_list *list_2); //rrr


void print_error(void);
int	ft_atoi_ps(char *str);
#endif

