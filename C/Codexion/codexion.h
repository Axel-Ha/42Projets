#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct parsing
{
	int				number_of_coders;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	char			*scheduler;
}					t_parsing;

typedef struct coder
{
	int				id_coder;
	pthread_t		id_thread_coder;
	char			etat;
	int				count_compilation;
	int				time_last_compile;
	t_dongle		dongle_up;
	t_dongle		dongle_down;
	pthread_mutex_t	mutex_coder;
	t_global		struct_global;
}					t_coder;

typedef struct dongle
{
	int				id_dongle;
	char			etat;
	int				time_before_ready;
	int				queue_priority;
	pthread_cond_t	cond_dongle;
	pthread_mutex_t	mutex_dongle;
}					t_dongle;

typedef struct global
{
	int				start_time;
	char			end_simulation;
	pthread_mutex_t	mutex_status;
	t_parsing		config;
}					t_global;

int					ft_check_atoi(const char *str);
int					parser(char *av[], t_parsing *config);
void				valid_arguments(char *av[], t_parsing *config);
