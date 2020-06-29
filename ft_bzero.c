#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "libft.h"

void test(void *org_src, void *ft_src, size_t len, int check_len)
{
	printf("\"%s\" len:%zu\n", ft_src, len);
	bzero(org_src, len);
	// bzero(ft_src, len);
	// ft_bzero(org_src, len);
	ft_bzero(ft_src, len);

	int dif = memcmp(org_src, ft_src, check_len);
	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("cmp => %d\n", dif);
	printf("print ascii.\n");
	printf("org: ");
	for (size_t i = 0; i < (size_t)check_len; i++)
	{
		printf("%d ", ((unsigned char*)org_src)[i]);
	}
	printf("\nft : ");
	for (size_t i = 0; i < (size_t)check_len; i++)
	{
		printf("%d ", ((unsigned char*)ft_src)[i]);
	}
	printf("\n"RESET);
}

int main(void)
{
	printf("== standard check ==\n");
	char org_src[] = "abcdefgh";
	char ft_src[] = "abcdefgh";
	int check_len = strlen(org_src);
	for (size_t i = 0; (int)i < check_len; i++)
	{
		test(org_src, ft_src, i, check_len);
	}

	// printf("\n== unusual check ==\n");

	// printf("> NULL input check <\n");
	// test(NULL, NULL, 1, check_len); // seg fault -> OK

	printf("\n↓leakcheck\n\n");
	while(1);
}
