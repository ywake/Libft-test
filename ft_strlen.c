#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"

int		main(void)
{
	printf("----------------------------\n");
	printf("--- start test ft_strlen ---\n");
	printf("----------------------------\n");

	char *test[] = {
		"test",
		"supercalifragilisticexpialidocious",
		"",
		"あいうえお",
		NULL
	};
	int i = 0;
	while (test[i])
	{
		printf("strlen(\"%s\") => `%lu`\n",test[i],strlen(test[i]));
		printf("ft_strlen(\"%s\") => `%zu`\n",test[i],ft_strlen(test[i]));
		i++;
	}
	printf("\n↓leakcheck\n\n");
	while(1);
}
