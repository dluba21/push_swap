#include "push_swap.h"

void print_error(void)
{
	printf("error\n");
	exit(0);
}

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

void	swap_sort(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int *indices_array_creator(int size_array)
{
	int	i;
	int *indices_array;

	i = 0;
	indices_array = (int *)malloc(sizeof(int) * size_array);
	if (!indices_array)
	{
		printf("no indices_array\n");
		exit(0);
	}
	while (i < size_array)
	{
		indices_array[i] = i + 1;
		i++;
	}
	return (indices_array);
}

void dublicate_check(t_parse *parse)
{
	int	i;
	int counter;
	int c;

	i = 0;
	counter = -1;
	c = parse->big_array[i];
	while (i < parse->size_array)
	{
		if (parse->big_array[i] == c)
			counter++;
		else
		{
			c = parse->big_array[i];
			counter = 0;
		}
		if (counter > 0)
		{
			printf("error: dublicates are here\n");
			exit(0);
		}
		i++;
	}
}


void quick_sort_array(t_parse *parse, int ind_array_flag) //replace bubble_sort to quick_sort
{
	int	i;
	int	j;
	int *first_array;
	int *second_array;

	if (ind_array_flag == 0)
		first_array = parse->big_array;
	if (ind_array_flag == 1)
		first_array = parse->ind_array;
	second_array = indices_array_creator(parse->size_array);
	i = 0;
	//	for (int k = 0; k < parse->size_array; k++) //show arrays before
	//		printf("[%d ", first_array[k]);
	//	printf("\n");
	//	for (int k = 0; k < parse->size_array; k++)
	//		printf("[%d ", second_array[k]);
	//		printf("\n");
	while (i < parse->size_array)
	{
		j = 0;
		while (j < parse->size_array - i - 1)
		{
			if (first_array[j] > first_array[j + 1]) //nuzhno urezat'
			{
				swap_sort(&first_array[j], &first_array[j + 1]);
				swap_sort(&second_array[j], &second_array[j + 1]);
			}
			j++;
		}
		i++;
	}
	if (ind_array_flag == 0)
		parse->ind_array = second_array;
	if (ind_array_flag == 1)
		parse->sort_ind_array = second_array;
//		for (int k = 0; k < parse->size_array; k++) //show arrays before
//			printf("[%d ", first_array[k]);
//		printf("\n");
//		for (int k = 0; k < parse->size_array; k++)
//			printf("[%d ", second_array[k]);
//			printf("\n");
}
void is_sorted_at_start(int *array, int size)
{
	int	i;

	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return ;
		i++;
	}
	printf("array is sorted at start\n");
	exit(0);
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
//	is_sorted_at_start(parse->big_array, parse->size_array); //!!!vkluchit' potom!!!!
	quick_sort_array(parse, 0); // flag = 0 is for initilizing first array; flag = 1 is for the second step and init second ind_arr;
	dublicate_check(parse); //nado free massive moduley i perviy massive indexov
	quick_sort_array(parse, 1); //second array of indices that will be in list,(stoit li dobavlyat '1', chtobi s nulya nachalo bilo?)
	
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
}

