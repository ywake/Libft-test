#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"

void	test(char const *s1, char const *set, char *expect)
{
	printf("> s1:\"%s\" set:\"%s\"", s1, set);
	char	*rtn = ft_strtrim(s1, set);
	int dif = ft_strncmp(expect, rtn, ft_strlen(expect + 1));
	dif == 0 ? printf(GREEN) : printf(BOLDRED);
	printf("    expect: \"%s\"\n", expect);
	printf("ft_strtrim: \"%s\"\n", rtn);
	printf(RESET);
	free(rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("  \t\t \ttest\t    \t\t", " \t", "test");

	printf("\n== advanced input ==\n");
	test("  \t\t \t\t    \t\t", " \t", "");
	// test("this is test", 5, 20);
	// test("this is test", 20, 5);
	// test("", 5, 3);
	// // test(NULL, 5, 3); -> seg fault
	// test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
