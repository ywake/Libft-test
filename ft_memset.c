#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "libft.h"

void test(void *org_src, void *ft_src, int c, int len, int check_len)
{
	if (ft_isprint(c))
		printf("\"%s\" < '%c' len:%d\n", ft_src, (char)c, len);
	void* org_rtn = memset(org_src, c, len);
	// void* ft_rtn = memset(ft_src, c, len);
	// void* org_rtn = ft_memset(org_src, c, len);
	void* ft_rtn = ft_memset(ft_src, c, len);

	int dif = memcmp(org_rtn, ft_rtn, check_len);
	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("cmp => %d\n", dif);
	printf("org: \"%s\"\n", org_rtn);
	printf("ft : \"%s\"\n", ft_rtn);
	printf(RESET);
}

int main(void)
{
	printf("== standard check ==\n");
	char org_src[] = "abcdefgh";
	char ft_src[] = "abcdeftg";
	int check_len = strlen(org_src);
	test(org_src, ft_src, '!', 8, check_len);
	test(org_src, ft_src, 't', 7, check_len);
	test(org_src, ft_src, 'c', 6, check_len);
	test(org_src, ft_src, 'e', 5, check_len);
	test(org_src, ft_src, 'r', 4, check_len);
	test(org_src, ft_src, 'o', 2, check_len);
	test(org_src, ft_src, 'c', 1, check_len);
	test(org_src, ft_src, '/', 0, check_len);

	printf("\n== unusual check ==\n");
	/* special character */
	int len = 1;
	printf("> special character check <\n");
	printf("\"%s\" < '\\n' len:%d\n", ft_src, len);
	test(org_src, ft_src, '\n', len, check_len);
	printf("\"%s\" < '\\0' len:%d\n", ft_src, len);
	test(org_src, ft_src, '\0', len, check_len);
	printf("    right of \\0\n");
	printf("    org: \"%s\"\n", org_src+1);
	printf("    ft : \"%s\"\n", ft_src+1);
	/* big input */
	printf("> big input check <\n");
	printf("\"%s\" < INT_MAX len:%d\n", ft_src, len);
	// len = 20;
	// test(org_src, ft_src, '.', len, 21); // ←lenをbigにすると領域がかぶるので正しく評価できない
	test(org_src, ft_src, INT_MAX, len, check_len);

	// printf("> NULL input check <\n");
	// test(NULL, NULL, 'a', len, check_len); // seg fault -> OK

	printf("\n↓leakcheck\n\n");
	while(1);
}
