#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("Before memset(): %s\n", str);
	
    // Fill 8 characters starting from str[13] with '.'
    ft_memset(str + 13, '.', 8*sizeof(char));
	
    printf("After memset():  %s\n", str);
    return 0;
}