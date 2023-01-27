#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	int x;

	x = 'z';
	while (x >= 'a')
	{
		write (1, &x, 1);
		x--;
	}
}
