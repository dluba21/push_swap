#include "push_swap.h"

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
