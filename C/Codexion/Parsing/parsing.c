/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:44:59 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/14 12:38:21 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	parser(char *av[])
{
	int	i;
	int	number;

	i = 1;
	while (i < 9)
	{
		if (strlen(av[i]) != 0)
		{
			if (ft_check_atoi(av[i]) == -1)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	if (strcmp(av[i], "fifo") != 0 && strcmp(av[i], "edf") != 0)
		return (-1);
}

struct_parsing	*valid_arguments(char *av[])
{
	struct_parsing	*config;
	int				result;

	config = malloc(sizeof(struct_parsing));
	if (!config)
		return (NULL);
	config->number_of_coders = ft_check_atoi(av[1]);
	config->time_to_burnout = ft_check_atoi(av[2]);
	config->time_to_compile = ft_check_atoi(av[3]);
	config->time_to_debug = ft_check_atoi(av[4]);
	config->time_to_refactor = ft_check_atoi(av[5]);
	config->number_of_compiles_required = ft_check_atoi(av[6]);
	config->dongle_cooldown = ft_check_atoi(av[7]);
	config->scheduler = av[8];
	return (config);
}

int	main(int ac, char *av[])
{
	if (ac == 9)
	{
		struct_parsing	*config;
		char			*c[10] = {"a.out", "1", "2", "3", "4", "5", "6", "7", "8",
						"fifo"};

		if (parser(c) == -1)
		{
			printf("Something wrong with the arguments");
			return (-1);
		}
		config = valid_arguments(c);
		printf("%d\n", config->dongle_cooldown);
		free(config);
	}
	else
		fprintf(stderr, "Some arguments are missing");
	return (0);
}
