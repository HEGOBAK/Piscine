#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (0);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
