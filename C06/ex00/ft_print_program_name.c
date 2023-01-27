#include <unistd.h>

void ft_print(char *str)
{
	int i = 0;

	while (str[i])
		write (1, &str[i++], 1);
}

int main(int argc, char **argv)
{
	if (argc >= 1)
		ft_print(argv[0]);
	return (0);
}
