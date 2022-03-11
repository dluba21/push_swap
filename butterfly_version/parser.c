#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	big_char_str_free(char **big_str)
{
	char	**temp_big_str;

	temp_big_str = big_str;
	while (*big_str)
		free(*big_str++);
	free(temp_big_str);
}

int	word_counter(char **big_str)
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

int	*indices_array_creator(int size_array)
{
	int	i;
	int	*indices_array;

	i = 0;
	indices_array = (int *)malloc(sizeof(int) * size_array);
	if (!indices_array)
		exit(0);
	while (i < size_array)
	{
		indices_array[i] = i + 1;
		i++;
	}
	return (indices_array);
}

void	dublicate_check(t_parse *parse)
{
	int	i;
	int	counter;
	int	c;

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
			print_error();
		i++;
	}
}

int	*bubble_sort_start(t_parse *parse, int ind_array_flag)
{
	if (ind_array_flag == 0)
		return (parse->big_array);
	else
		return (parse->ind_array);
}

void	bubble_sort_end(t_parse *parse, int ind_array_flag, int	*second_array)
{
	if (ind_array_flag == 0)
		parse->ind_array = second_array;
	if (ind_array_flag == 1)
		parse->sort_ind_array = second_array;
}

void	bubble_sort_array(t_parse *parse, int ind_array_flag)
{
	int	i;
	int	j;
	int	*first_array;
	int	*second_array;

	first_array = bubble_sort_start(parse, ind_array_flag);
	second_array = indices_array_creator(parse->size_array);
	i = 0;
	while (i < parse->size_array)
	{
		j = 0;
		while (j < parse->size_array - i - 1)
		{
			if (first_array[j] > first_array[j + 1])
			{
				swap_sort(&first_array[j], &first_array[j + 1]);
				swap_sort(&second_array[j], &second_array[j + 1]);
			}
			j++;
		}
		i++;
	}
	bubble_sort_end(parse, ind_array_flag, second_array);
}

void	big_array_creator(t_parse *parse)
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
	bubble_sort_array(parse, 0);
	dublicate_check(parse);
	bubble_sort_array(parse, 1);
}

void	num_array_dealer(int argc, char **argv, t_parse *parse)
{
	int		i;
	char	*long_str;
	char	*temp_to_free_str;
	char	*temp;

	i = 1;
	long_str = ft_strdup(" ");
	while (i < argc)
	{
		temp = long_str;
		long_str = ft_strjoin(long_str, argv[i++]);
		free(temp);
		temp_to_free_str = ft_strdup(" ");
		temp = long_str;
		long_str = ft_strjoin(long_str, temp_to_free_str);
		free(temp);
		free(temp_to_free_str);
	}
	parse->big_str = ft_split(long_str, ' ');
	free(long_str);
	parse->size_array = word_counter(parse->big_str);
	big_array_creator(parse);
	big_char_str_free(parse->big_str);
	free(parse->big_array);
	free(parse->ind_array);
}
