#include <unistd.h>
#include "ft_stock_str.h"
void ft_putchar(char c)
{
	write (1, &c, 1);
}
	
void ft_putstr(char *str)
{
	int i;
	while (str[i])
		ft_putchar(str[i++]);
}

void ft_putnbr(int nbr)
{
	if (nbr < 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void ft_show_tab(struct s_stock_str *par)
{
	while (par -> str != 0)
	{
		ft_putstr(par -> str);
		write (1, "\n", 1);
		ft_putnbr(par -> size);
		write (1, "\n", 1);
		ft_putstr(par -> copy);
		write (1, "\n", 1);
		par++;
	}
}
