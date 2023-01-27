#include <unistd.h>

int add(int num, int num1)
{
    return (num + num1);
}

int minus(int num, int minus)
{
    return (num - minus);
}

int multiply(int num, int num1)
{
    return (num * num1);
}

int divide(int num, int div)
{
    return (num / div);
}

int module(int num, int mod)
{

    return (num % mod);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int check_operator(char *op)
{
    if (ft_strlen(op) != 1)
        return (0);
    else if (op[0] == '+')
        return (1);
    else if (op[0] == '-')
        return (2); 
    else if (op[0] == '*')
        return (3);
    else if (op[0] == '/')
        return (4);
    else if (op[0] == '%')
        return (5); 
    else
        return (0);
}

void ft_putchar(char a)
{
    write (1, &a, 1);
}

void ft_putnum(int nb)
{
    if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnum(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnum(nb * -1);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnum(nb / 10);
		ft_putnum(nb % 10);
	}
}

int ft_atoi(char *str)
{
	int i = 0;
	long result = 0;
	int sign = 1;

	if ((!(str[i] >= '0' && str[i] <= '9')) && (str[i] != '+' || str[i] != '-') )
        return 0;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result += str[i] - '0';
		result *= 10;
		i++;
	}
	result /= 10;
	return (result * sign);
}

int main(int argc, char **argv)
{
    int a;
    int b;
    int c;

    if (argc != 4)
        return(0);
    
    c = check_operator(argv[2]);

    if (c == 0)
        write (1, "0", 1);
    else
    {
        a = ft_atoi(argv[1]);
        b = ft_atoi(argv[3]);
        if (c == 1)
            ft_putnum(add(a, b));
        else if (c == 2)
            ft_putnum(minus(a, b));
        else if (c == 3)
            ft_putnum(multiply(a, b));
        else if (c == 4)
        {
            if (b == 0)
                write (1, "Stop : division by zero", 23);
            else
                ft_putnum(divide (a, b));

        }
        else
            if (b == 0)
                write (1, "Stop : modulo by zero", 21);
            else
                ft_putnum(module(a, b));
    }
    return (0);
}
