/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:47:38 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/30 12:05:39 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h" 

int main(int ac, char *av[])
{
	t_parsing	*config;

	if (ac == 9)
	{
		config = malloc(sizeof(t_parsing));
		if (!config)
			return (1);
		if (parser(av, config) == 1)
		{
			free(config);
			fprintf(stderr, "Something wrong with the arguments\n");
			return (1);
		}
		valid_arguments(av, config);
		printf("Number of coder %d\n",config->number_of_coders);
		printf("time to burnout %d\n",config->time_to_burnout);
		printf("time to compile %d\n",config->time_to_compile);
		printf("time to debug %d\n",config->time_to_debug);
		printf("time to refactor %d\n",config->time_to_refactor);
		printf("number of compiles requiered %d\n",config->number_of_compiles_required);
		printf("dongle cooldown %d\n",config->dongle_cooldown);
		printf("scheduler %s\n",config->scheduler);
	}
	else
	{
		fprintf(stderr, "Some arguments are missing\n");
		return (1);
	}
	free(config);
	return (0);
}