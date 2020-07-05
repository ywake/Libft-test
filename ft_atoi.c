#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "libft.h"
// #include "../Libft/ft_atoi.c"

void test(char *str)
{
	int org_rtn = atoi(str);
	// int ft_rtn = atoi(str);
	int ft_rtn = ft_atoi(str);

	printf("> \"%s\"\n", str);
	(org_rtn == ft_rtn) ? printf(GREEN) : printf(RED);
	printf("org: %d\n", org_rtn);
	printf("ft : %d\n", ft_rtn);
	printf(RESET);
}

void advanced_test(char *str)
{
	long org_rtn = atoi(str);
	long ft_rtn = atoi(str);
	// int ft_rtn = ft_atoi(str);

	(org_rtn == ft_rtn) ? printf(GREEN) : printf(RED);
	printf("org: %ld\n", org_rtn);
	printf("ft : %ld\n", ft_rtn);
	printf(RESET);
}

int main(void)
{
	printf("== basic input ==\n");
	test("123");
	test("+123");
	test("-123");
	test("+-+123");
	test("123a");
	test("-123a");
	test("abc123");
	test("abcdefg");

	printf("\n== advanced input ==\n");
	printf("> \" \\t\\n\\r\\v\\f123\"\n");
	advanced_test(" \t\n\r\v\f123");
	printf("> \" \\t\\n\\r\\v\\f-123\"\n");
	advanced_test(" \t\n\r\v\f-123");
	test("- 123");
	test("2147483647");
	test("-2147483648");
	test("9223372036854775806");
	test("-922337203685477580");
	test("9223372036854775808");
	test("-9223372036854775809");

	printf("\n↓leakcheck\n\n");
	while(1);
}
