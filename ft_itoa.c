#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "test.h"
#include "libft.h"
// #include "../Libft/ft_itoa.c"

void	test(int n)
{
	printf("> n: %d\n", n);
	char	*rtn = ft_itoa(n);
	char expect[12];
	ft_bzero(expect, 12);
	snprintf(expect, 12, "%d", n);
	int dif = ft_strncmp(expect, rtn, ft_strlen(expect + 1));
	dif == 0 ? printf(GREEN) : printf(BOLDRED);
	printf(" expect: \"%s\"\n", expect);
	printf("ft_itoa: \"%s\"\n", rtn);
	printf(RESET);
	free(rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test(0);
	test(1);
	test(100);
	test(-100);
	test(INT_MAX);
	test(INT_MIN);

	// printf("\n== advanced input ==\n");
	// test("this is test", 5, 20);
	// test("this is test", 20, 5);
	// test("", 5, 3);
	// // test(NULL, 5, 3); -> seg fault
	// test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
