#include <stdlib.h>
int check_c(char c, char *charset)
{
	int i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int t_strs(char *str, char *charset)
{
	int index = 0;
	int count = 0;

	while (check_c(str[index], charset))
		index++;
	while (str[index])
	{
		if (!(check_c(str[index], charset)))
		{
			count++;
			while (!(check_c(str[index], charset)))
				index++;
		}
		index++;
	}
	return (count);
}

char *create_str(char *str, char *charset)
{
	char *final;
	int len = 0;

	while (!check_c(str[len], charset))
		len++;

	final = (char *)malloc(sizeof(char) * len + 1);
	if (final == NULL)
		return (0);

	len = 0;
	while (!(check_c(str[len], charset)))
	{
		final[len] = str[len];
		len++;
	}
	final[len] = '\0';
	return (final);
}

char **ft_split(char *str, char *charset)
{
	char **res;
	int i = 0;
	int t_elements = t_strs(str, charset);

	res = (char **)malloc(sizeof(char *) * (t_elements + 1));
	if (res == NULL)
		return (0);

	while (*str)
	{
		while (*str && check_c(*str, charset))
			str++;
		if (*str)
		{
			res[i] = create_str(str, charset);
			i++;
		}
		while (*str && !check_c(*str, charset))
				str++;
	}
	res[i] = 0;
	return (res);
}

/*#include <stdio.h>
int main()
{
	int i = 0;
	char **tab = ft_split("lhlello", "1");

	while (tab[i] != 0)
	{
		printf ("%s", tab[i]);
		i++;
	}
	return (0);
}*/
