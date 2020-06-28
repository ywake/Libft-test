#include <stdio.h>
#include <string.h>
#include "test.h"
// #include "../Libft/libft.h"
#include "../Libft/ft_strmapi.c"

char func(unsigned int n, char c)
{
	(void)n;
	return (char)ft_toupper((int)c);
}

void	test(char *src, char *expect)
{
	printf("> \"%s\"\n", src);
	char	*rtn = ft_strmapi(src, func);
	int dif = ft_strncmp(expect, rtn, ft_strlen(expect + 1));
	dif == 0 ? printf(GREEN) : printf(BOLDRED);
	printf("    expect: \"%s\"\n", expect);
	printf("ft_strmapi: \"%s\"\n", rtn);
	printf(RESET);
	free(rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("This is test.", "THIS IS TEST.");
	test("", "");

	// printf("\n== advanced input ==\n");
	// test("this is test", 5, 20);
	// test("this is test", 20, 5);
	// test("", 5, 3);
	// // test(NULL, 5, 3); -> seg fault
	// test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
