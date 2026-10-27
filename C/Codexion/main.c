/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:47:38 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/27 16:05:28 by ahalifa          ###   ########.fr       */
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
	}
	else
	{
		fprintf(stderr, "Some arguments are missing\n");
		return (1);
	}
	free(config);
	return (0);
}