#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void	test(char *src){
	char	*org_rtn = strdup(src);
	// char	*ft_rtn = strdup(src);
	char	*ft_rtn = ft_strdup(src);

	printf("> \"%s\"\n", src);
	(strcmp(org_rtn,ft_rtn) == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("org:\"%s\"\n", org_rtn);
	printf("ft :\"%s\"\n", ft_rtn);
	printf(RESET);
	free(org_rtn);
	free(ft_rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("test");
	test("test test");

	printf("\n== advanced input ==\n");
	test("");
	test("\200\t\x41\0");
	// test(NULL); -> segmentation fault

	printf("\n↓leakcheck\n\n");
	while(1);
}
