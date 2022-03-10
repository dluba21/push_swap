#include "push_swap.h"


t_node *create_elem(int value)
{
	t_node	*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (!new_elem)
		return (0);
	new_elem->value = value;
	new_elem->flag = 0;
	new_elem->next = NULL;
	return (new_elem);
}

int list_length(t_list *list)
{
	t_node *temp;
	int		i;

	if (!list || !list->head)
		return (0);
	i = 1;
	temp = list->head;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
	
}

t_node *get_last_elem(t_list *list)
{
	t_node *temp;

	if (!list || !list->head)
		return (NULL);
	temp = list->head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void add_front_list(t_list *list, t_node *elem)
{
	if (!list || !elem)
	{
		printf("add_front_lst error");
		exit(0);
	}
	elem->next = list->head;
	list->head = elem;
}


void add_back_list(t_list *list, t_node *elem)
{
	t_node	*temp;
	
	if (!list || !elem)
	{
		printf("add_back_lst error\n");
		exit(0);
	}
	temp = get_last_elem(list);
	if (!temp)
	{
		list->head = elem;
		return ;
	}
	temp->next = elem;
}

void print_list(t_list *list)
{
	t_node *temp;

	temp = list->head;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	
}

void print_list_and_flag(t_list *list)
{
	t_node *temp;

	temp = list->head;
	while (temp)
	{
		printf("%d [%d]\n", temp->value, temp->flag);
		temp = temp->next;
	}
}

void print_list_in_line(t_list *list, int stack_flag)
{
	t_node *temp;

	temp = list->head;
	if (stack_flag == 1)
		printf("stack_A: ");
	else if (stack_flag == 2)
		printf("stack_B: ");
	while (temp)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("[next: %d | ", list->next);
	printf("size: %d]", list->size);
	printf("\n");
	
}

t_list *list_init(int size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
	{
		printf("init_lst error: malloc\n");
		exit(0);
	}
	list->head = NULL;
	list->size = size;
	
	list->number_of_operations = 0; //just for check, delete it
	return (list);
}

t_list *create_list(int size)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 0;
	list = list_init(size);
	list->size = size;
	temp = list->head;
	while (i < list->size)
	{
		add_back_list(list, create_elem(0));
		i++;
	}
	list->next = 1;
	return (list);
}


t_list *create_list_from_argv(int size, int *sort_ind_array)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 0;
	list = list_init(size);
	temp = list->head;
	while (i < list->size)
		add_back_list(list, create_elem(sort_ind_array[i++]));
	list->next = 1;
	return (list);
}

void free_list(t_list *list)
{
	t_list	*temp_list;
	t_node	*temp_node;
	t_node	*node;

	temp_list = list;
	node = list->head;
	while (node)
	{
		temp_node = node->next;
		free(node);
		node = temp_node;
	}
	free(temp_list);
}

t_list *copy_list(t_list *list)
{
	t_list	*new_list;
	t_node	*temp_old_lst;
	t_node	*temp_new_lst;

	if (!list)
	{
		printf("error: can't copy");
		exit(0);
	}
	temp_old_lst = list->head;
	if (!temp_old_lst)
		return (create_list(0));
	new_list = create_list(list->size);
//	if (!new_lst)
//		exit(0);
	temp_new_lst = new_list->head;
	while (temp_old_lst != NULL)
	{
		temp_new_lst->value = temp_old_lst->value;
		temp_new_lst = temp_new_lst->next;
		temp_old_lst = temp_old_lst->next;
	}
	return (new_list);
}

int is_sort(t_list *list)
{
	t_node	*temp;

	if (!list || !list->head)
		return (0);
	if (list->size == 1)
		return (1);
	temp = list->head;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

//int main()
//{
//	t_list *list_1;
//	t_list *list_2;
//	
//	list_1 = list_init(10);
//}
