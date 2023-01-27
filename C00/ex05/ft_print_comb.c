#include <unistd.h>

void ft_print_comb(void)
{
	int x = 48;
	int y = 49;
	int z = 50;
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = 1 + y;
			while (z <= '9')
			{
				write (1, &x, 1);
				write (1, &y, 1);
				write (1, &z, 1);
				if (x != '7')
					write (1, ", ", 2);
				z++;
			}
			y++;
		}
		x++;
	}
}
