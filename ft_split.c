#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"
// #include "../Libft/ft_split.c"

void	test(char const *s, char c)
{
	printf("> src:\"%s\" c:'%c'\n", s, c);
	char	**rtn = ft_split(s, c);
	// int dif = ft_strncmp(expect, rtn, ft_strlen(expect + 1));
	// dif == 0 ? printf(GREEN) : printf(BOLDRED);
	// printf("    expect: \"%s\"\n", expect);
	int i = 0;
	while (rtn[i] != NULL)
	{
		printf("\"%s\"\n", rtn[i]);
		free(rtn[i]);
		i++;
	}
	if (rtn[i] == NULL)
		printf("NULL\n");
	free(rtn);
	// printf(RESET);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("this is test", ' ');
	test(" this is test ", ' ');
	test("   this    is   test", ' ');

	printf("\n== advanced input ==\n");
	test("\0 this is test ", ' ');
	test("   ", ' ');
	test("split  ||this|for|me|||||!|", '|');
	test("      split       this for   me  !       ", ' ');
	test("", '\0');
	test("\0 this is test ", '\0');
	// test("  \t\t \t\t    \t\t", " \t", "");
	// test("this is test", 5, 20);
	// test("this is test", 20, 5);
	// test("", 5, 3);
	// // test(NULL, 5, 3); -> seg fault
	// test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
