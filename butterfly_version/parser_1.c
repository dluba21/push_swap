#include "push_swap.h"

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
