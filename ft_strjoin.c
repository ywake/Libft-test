#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void	test(char *s1, char *s2)
{
	printf("> s1:\"%s\" s2:\"%s\"\n", s1, s2);
	char	*ft_rtn = ft_strjoin(s1, s2);
	printf("res: \"%s\"\n", ft_rtn);
	free(ft_rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("abcde", "fghij");

	printf("\n== advanced input ==\n");
	test("", "fghij");
	test("abcde", "");
	test("\200\t\x41\0", "test");
	// test(NULL, "null"); -> seg fault

	printf("\n↓leakcheck\n\n");
	while(1);
}
