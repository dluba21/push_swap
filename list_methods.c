#include "push_swap.h"


t_node *create_elem(long value)
{
	t_node	*new_elem;

	new_elem = (t_node *)malloc(sizeof(t_node));
	if (!new_elem)
		return (0);
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}

void add_front_list(t_list *list, long value)
{
	t_node *temp;

	if (!list)
		return ;
	temp = create_elem(value);
	temp->next = list->head;
	list->head = temp;
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



t_list *create_list(int size, char **argv, t_errors *error)
{
	t_node	*temp;
	t_list	*list;
	int		i;

	i = 1;
	list = (t_list *)malloc(sizeof(t_list));
	list->size = size;
	temp = list->head;
	while (i < list->size)
//		temp = create_elem(ft_atoi(argv[i++], error));
	add_front_list(list, ft_atoi(argv[i++], error));
	return (list);
}

int main(int argc, char **argv)
{
	t_errors error;
	error.atoi_flag = 0;
	t_list *list;
	
//	printf("%d", argc);
	
	if (argc < 2)
		return (0);
	list = create_list(argc, argv, &error);
	if (error.atoi_flag == 1)
		return (0);
//	xt);
		printf("\n\n%d\n", list->head->value);
//		printf("%p\n", list->head->next->next);
//		add_front_list(list, 1);
//		printf("\n\n%p\n", list->head->ne
	return (0);
}






//int main()
//{
//	t_list *list;
//	list = (t_list *)malloc(sizeof(t_list));
////	t_stack *temp = *head;
////	temp = create_elem(-1);
//	add_front_list(list, 1);
////	printf("\n\n%p\n", list->head->next);
////	add_front_list(list, 1);
////	printf("\n\n%p\n", list->head->next);
////	printf("%p\n", list->head->next->next);
////	add_front_list(list, 1);
////	printf("\n\n%p\n", list->head->next);
////	printf("%p\n", list->head->next->next);
////	printf("%p\n", list->head->next->next->next);
////	add_front_list(list, 1);
////	add_front_list(list, 1);
////	list = create_list(7);
////	printf("%p\n", *head->next);
//	
//	printf("%d", list_length(list));
//	return (0);
//}
