#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *res;

	if (min >= max)
		return (0);

	res = (int)malloc(max - min);
	if (res == NULL)
		return (0);

	int i = 0;
	while (i < max - min)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}

int ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
