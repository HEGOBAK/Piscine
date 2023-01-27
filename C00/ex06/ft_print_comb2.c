#include <unistd.h>

void ft_putchar(char a)
{
	write (1, &a, 1);
}

void ft_putnum(int a, int b, int check)
{
	ft_putchar(48 + a / 10);
	ft_putchar(48 + a % 10);
	ft_putchar(' ');
	ft_putchar(48 + b / 10);
	ft_putchar(48 + b % 10);
	if (check == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_print_comb2()
{
	int a;
	int b;
	int check;

	a = 0;
	while (a <= 98)
	{
		b = a + 1; 
		while (b <= 99)
		{
			check = !(a == 98 && b == 99);
			ft_putnum(a, b, check);
			b++;
		}
		a++;
	}
}
