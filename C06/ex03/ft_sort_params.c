#include <unistd.h>
void swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_print(char *str)
{
	int i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int main(int argc, char ** argv)
{
	int j = 1;

	while (j < argc)
	{
		int i = 1;
		while (i < argc - j)
		{
			if (ft_strcmp(argv[j], argv[j + i]) > 0)
				swap(&argv[j], &argv[j + i]);
			i++;
		}
		j++;
	}

	j = 0;
	while (++j < argc)
	{
		ft_print(argv[j]);
		write (1, "\n", 1);
	}
	return (0);
}
