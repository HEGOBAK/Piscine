#include <unistd.h>

void ft_print(char *str)
{
	int i = 0;

	while (str[i])
		write (1, &str[i++], 1);
}

int main(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_print(argv[argc - 1]);
		write (1, "\n", 1);
		argc--;
	}
	return (0);
}
