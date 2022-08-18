



// utils.c

#include <strings.h>
#include <stdlib.h>
int main()
{
	int i;
	char my_text[2][10];

	*my_text[0] = ft_strdup("psydenst:");
	*my_text[1] = ft_strdup("psydenst:");

	char result[][] = splitting_paths(my_text);
	i = 0;
	while(i < 2)
	{
	printf("%s\n", result[i]);
	i++;
	}
}
