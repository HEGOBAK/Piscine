#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>

# define BUFFER 1024

/* ----------- opt_c ----------- */
int ft_strlen(char *str);

int ft_opt_c(int argc, char **argv);

void ft_read_stdin(void);

/* ----------- count_line ----------- */
char *ft_str_sized_copy(char *dest, char *src, unsigned int src_size);

char	*read_full(int fd, unsigned long *total_read);

int		count_line(unsigned long byte_read, char *content);

/* ----------- error_handling ----------- */
void ft_putstr(char *str);

void error_absent(char *program_name, char *file);

void error_ill_opt(char *program_name, char *opt);

void error_ill_off(char *program_name, char *off);

void error_opt_requirements(char *program_name);

void error_inv_opt(char *program_name, char opt);

/* ----------- atoi ----------- */
int ft_atoi(char *str);

/* ----------- default ----------- */
void display_file(char *file);

void ft_seperator(char *file);

int ft_default(int argc, char **argv);

/* ----------- default_opts ----------- */
int ft_check_opt(char *arg);

int ft_default_opts(int argc, char **argv);

#endif


