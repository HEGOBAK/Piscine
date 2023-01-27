#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_arraylen(char **array, int size)
{
	int i = 0;
	int result;

	while (i < size)
	{
		result += ft_strlen(array[i]);
		i++;
	}
	return (result);
}

void ft_concatenate(char *dest, int size, char **array, char *sep)
{
	int i;
	int y;
	int k = 0;
	int x = 0;

	while (x < size)
	{
		i = 0;
		y = 0;
		while (array[x][i])
			dest[k++] = array[x][i++];

		if (x != size - 1)
		{
			while (sep[y])
				dest[k++] = sep[y++];
		}
		x++;
	}
	dest[k] = 0;
}
char *ft_strjoin(int size, char **str, char *sep)
{
	char *dest;

	dest = (char *)malloc(ft_arraylen(str, size) + (ft_strlen(sep) * (size - 1)) + 1);
	if (dest == NULL)
		return (0);
	
	ft_concatenate(dest, size, str, sep);
	return (dest);
}

#include <stdio.h>
int main()
{
	char *tab[3] = {"H", "E", "LLO"};
	printf ("%s", ft_strjoin(3, tab, "-"));
	return (0);
}
