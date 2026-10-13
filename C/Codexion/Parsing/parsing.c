/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalifa <ahalifa@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:44:59 by ahalifa           #+#    #+#             */
/*   Updated: 2026/10/13 11:55:46 by ahalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int parser(char *av[])
{
    int i;

    i = 1;
    while(i < 9){
        if(strlen(av[i]) != 0)
        {
            printf("value i : %s\n" , av[i]);
            
        }
        else
        {
            printf("Argument can't be empty\n");
            return (0);    
        }
        i++;
    }
    if(av[i] != "fifo" || av[i] != "edf")
    {
        printf("Your scheduler needs to be 'fifo' or 'edf'");
        return (0);
    }
}

int main(void)
{
    char *c[10] = {"a.out","1","2","3","4","5","6","7","8","fifo"};
    parser(c);
}