#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct parsing
//{
//	int			number_of_coders;
//	int			time_to_burnout;
//	int			time_to_compile;
//	int			time_to_debug;
//	int			time_to_refactor;
//	int			number_of_compiles_required;
//	int			dongle_cooldown;
//	char		*scheduler;
//}				s_parsing;


typedef struct parsing
{
	int			arguments[7];
	char		*scheduler;
}				s_parsing;

int				ft_check_atoi(const char *str);
//int				parser(char *av[]);
int	parser(char *av[], s_parsing *config);
s_parsing	*valid_arguments(char *av[]);
