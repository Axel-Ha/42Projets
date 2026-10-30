#ifndef CODEXION_H
# define CODEXION_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

typedef struct s_parsing	t_parsing;
typedef struct s_coder		t_coder;
typedef struct s_dongle		t_dongle;
typedef struct s_simulation	t_simulation;
typedef struct s_queue		t_queue;

struct						s_parsing
{
	int						number_of_coders;
	int						time_to_burnout;
	int						time_to_compile;
	int						time_to_debug;
	int						time_to_refactor;
	int						number_of_compiles_required;
	int						dongle_cooldown;
	char					*scheduler;
};

struct						s_queue
{
	int						id_coder;
	long long				key;
	t_queue					*next;
};

struct						s_dongle
{
	int						id_dongle;
	char					*etat;
	struct timespec			time_before_ready;
	t_queue					*queue_priority;
	pthread_cond_t			cond_dongle;
	pthread_mutex_t			mutex_dongle;
};

struct						s_coder
{
	int						id_coder;
	pthread_t				id_thread_coder;
	char					*etat;
	int						count_compilation;
	struct timespec			time_last_compile;
	t_dongle				*dongle_up;
	t_dongle				*dongle_down;
	pthread_mutex_t			mutex_coder;
	t_simulation			*struct_simulation;
};

struct						s_simulation
{
	struct timespec			start_time_simulation;
	char					*status_simulation;
	pthread_mutex_t			mutex_status;
	t_parsing				*config;
	pthread_t				thread_monitor;
	t_coder					**array_coders;
	t_dongle				**array_dongles;
};

int							ft_check_atoi(const char *str);
int							parser(char *av[], t_parsing *config);
void						valid_arguments(char *av[], t_parsing *config);
t_simulation				*init_struct_simulation(t_parsing *config);
t_coder						*init_struct_coder(t_simulation *simulation,
								t_dongle *dongle_up, t_dongle *dongle_down,
								int id);
t_dongle					*init_struct_dongle(int id);
t_queue						*init_struct_queue_priority(int id_coder,
								long long key);
int							ft_free(t_parsing *config, t_coder **coders,
								t_dongle **dongles, t_simulation *monitor,
                            int num);

#endif