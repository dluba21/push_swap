#include "push_swap.h"

void print_error(void)
{
	printf("error\n");
	exit(0);
}


typedef struct	s_parse
{
	char 	**big_str;
	int		*big_array;
	int		size_array;
	
	int		*ind_array;
	int		*sort_ind_array;
	
}				t_parse;

int word_counter(char **big_str)
{
	int	i;

	i = 0;
	if (!big_str)
		return (0);
	while (big_str[i])
		i++;
	return (i);
}
void print_big_array(int *array, int size)
{
	if (!array)
	{
		printf("lol not print\n");
		exit(0);
	}
	printf("\n");
	for (int i; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
//	printf("ok\n");
}

void print_big_str(char **big_str)
{
	printf("\n");
	while(*big_str)
	{
		printf("%s ", *big_str++);
	}
	printf("\n");
}

void indices_array_creator(int *indices_array, int size_array)
{
	int	i;

	i = 0;
	indices_array = (int *)malloc(sizeof(int) * size_array);
	if (!indices_array)
	{
		printf("no indices_array\n");
		exit(0);
	}
	while (i < size_array)
	{
		indices_array[i] = i;
		i++;
	}
}

void quick_sort_array(t_parse *parse) //replace bubble_sort to quick_sort
{
	int	temp;
	int	i;
	int	j;
	int *indices_array;

	i = 1;
//	if (ind_array_flag == 1)
		indices_array = parse->ind_array;
	indices_array_creator(indices_array, parse->size_array);
	while (i < parse->size_array)
	{
		j = 0;
		while (j < parse->size_array - i)
		{
			if (parse->big_array[j] > parse->big_array[j + 1]) //nuzhno urezat'
			{
				temp = parse->big_array[j];
				parse->big_array[j] = parse->big_array[j + 1];
				parse->big_array[j + 1] = temp;

//				temp = indices_array[j];
//				indices_array[j] = indices_array[j + 1];
//				indices_array[j + 1] = temp;
			}
//			printf("i = %d\tj = %d\n", i, j);
			j++;
		}
//		printf("\n");
		i++;
	}
}

void big_array_creator(t_parse *parse)
{
	int	i;

	i = 0;
	parse->big_array = (int *)malloc(sizeof(int) * parse->size_array);
	if (!parse->big_str || !parse->big_array)
		print_error();
	while (i < parse->size_array)
	{
		parse->big_array[i] = ft_atoi_ps(parse->big_str[i]);
		i++;
	}
	print_big_array(parse->big_array, parse->size_array);
	print_big_array(parse->big_array, parse->size_array);
	quick_sort_array(parse);
//	printf("\n\n\n{{\n\n");
	print_big_array(parse->big_array, parse->size_array);
//	dublicate_check(parse->size_array);
}

void num_array_dealer(int argc, char **argv, t_parse *parse)
{
	int		i;
	char	*long_str;

	
	i = 1; //leaks here because of strdup
	long_str = ft_strdup(" ");
	while (i < argc)
	{
		long_str = ft_strjoin(long_str, argv[i++]);
		long_str = ft_strjoin(long_str, ft_strdup(" "));
	}
	parse->big_str = ft_split(long_str, ' ');
	parse->size_array = word_counter(parse->big_str);
	big_array_creator(parse);
//	quick_sort(parse);
//	dublicate_checker
////	print_big_array(parse->big_array, parse->size_array);
//
	
}
//void norm_argv(int *argc, char **argv)
//{
//
//}
//
//t_list *parsing(int argc, char **argv)
//{

//}
int main(int argc, char **argv)
{
	t_list *list;
	t_node *temp;
	t_parse	parse;

	
	if (argc < 2)
	{
		printf("\ntoo few arguments\n");
		return (0);
	}
//	printf("lol");
	num_array_dealer(argc, argv, &parse);
		
	
	
//	swap_ab(list);
//	print_list(list);
//	printf("\n");
//	rev_rotate_one(list);
//	print_list(list);
//	printf("[%d]", ((end - start)));
//	printf("\n{%d}", is_sort(list));
	return (0);
}
