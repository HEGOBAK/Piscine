#include "ft.h"

int ft_atoi(char *str)
{
    int count;
    int index;
    int result;

    count = 0;
    result = 0;
    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == '-' || str[index] == '+')
        {
            if (count != 0)
                return (0);
            index++;
        }
        if (!(str[index] >= '0' && str[index] <= '9'))
            return (0);
        result *= 10;
        result += str[index] - '0';
        count++;
        index++;
    }
    return (result);
}