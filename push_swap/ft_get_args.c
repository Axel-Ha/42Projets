#include "push_swap.h"

t_flags	ft_get_args(char **av, int *start)
{
	t_flags	flags;

	flags.algo = 4;
	flags.bench = 0;
	while (av[*start] && av[*start][0] == '-')
	{
		if (ft_strncmp("--simple", av[*start], 9) == 0)
			flags.algo = 1;
		if (ft_strncmp("--medium", av[*start], 9) == 0)
			flags.algo = 2;
		if (ft_strncmp("--complex", av[*start], 10) == 0)
			flags.algo = 3;
		if (ft_strncmp("--adaptive", av[*start], 11) == 0)
			flags.algo = 4;
		if (ft_strncmp("--bench", av[*start], 8) == 0)
			flags.bench = 1;
		(*start)++;
	}
	return (flags);
}

int	ft_check_nbrs(char **av, int pos, int ac)
{
	/*faire un appel deatoi sur chaque chiffre ? 
	va bouffer des perfs de faire atoi a chaque fois ?
	travailler comme ca pour linstant ?
	atoi retourne le chiffre 
	si le chiffre retourner == 0  alors c'est pas bon
	faire une var temp, qui le prend le 1er chiffre
	check si ce chiffre la est bien un chiffre

	ensuite boucler sur av
	check si tmp existe pas
	len sera ac.
	pos est notre start, on sait que les chiffres avants ont etait check, donc pas de possibilite de doublon

	faire comme un union(av, tmp, pos, ac))

	atoi doit check si c'est bien un chiffre
	ensuite on fait un union pour voir si on a un doublon
	*/
    return (0);
}

int	ft_union(char **av, char tmp, int pos, int ac)
{
	while(av[pos])
}