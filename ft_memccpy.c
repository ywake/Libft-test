#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
// #include "../Libft/libft.h"
#include "../Libft/ft_memccpy.c"

void test(void *org_dst, void *ft_dst, void *src, char c, int len, int check_len)
{
	check_len = 0;
	printf("\"%s\" < \"%s\" len:%d\n", org_dst, src, len);
	void* org_rtn = memccpy(org_dst, src, c, len);
	// void* ft_rtn = memccpy(org_dst, src, c, len);
	// void* org_rtn = ft_memccpy(src, c, len);
	void* ft_rtn = ft_memccpy(ft_dst, src, c, len);

	org_rtn == NULL ? org_rtn = org_dst : 0;
	ft_rtn == NULL ? ft_rtn = ft_dst : 0;
	(org_rtn-org_dst == ft_rtn-ft_dst) ? printf(GREEN) : printf(BOLDRED);
	// printf("cmp => %d\n", dif);
	printf("org: rtn=<+%ld> \"%s\"\n", org_rtn-org_dst, org_dst);
	printf("ft : rtn=<+%ld> \"%s\"\n", ft_rtn-ft_dst , ft_dst);
	printf(RESET);
}

// void special_test(void *org_dst, void *ft_dst, void *src, char c, int len, int check_len)
// {
// 	void* org_rtn = memccpy(org_dst, src, c, len);
// 	// void* ft_rtn = memccpy(src, c, len);
// 	// void* org_rtn = ft_memccpy(src, c, len);
// 	void* ft_rtn = ft_memccpy(ft_dst, src, c, len);
// 	int dif = memcmp(org_rtn, ft_rtn, check_len);
// 	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
// 	printf("cmp => %d\n", dif);
// 	printf("print ascii.\n");
// 	printf("org: ");
// 	for (size_t i = 0; i < (size_t)check_len; i++)
// 	{
// 		printf("%d ", ((unsigned char*)org_rtn)[i]);
// 	}
// 	printf("\nft : ");
// 	for (size_t i = 0; i < (size_t)check_len; i++)
// 	{
// 		printf("%d ", ((unsigned char*)ft_rtn)[i]);
// 	}
// 	printf("\n"RESET);
// }

int main(void)
{
	char src[] = "abcdefgh";
	int check_len = 10;
	char org_dst[check_len];
	char ft_dst[check_len];
	ft_memset(org_dst, 0, check_len);
	ft_memset(ft_dst, 0, check_len);
	char c = 'd';
	printf("== standard check ==\n");
	test(org_dst, ft_dst, src, c, 0, check_len);
	test(org_dst, ft_dst, src, c, 1, check_len);
	test(org_dst, ft_dst, src, c, 8, check_len);
	test(org_dst, ft_dst, src, c, 10, check_len);

	// printf("\n== unusual check ==\n");
	// /* special character */
	// printf("> special character check <\n");
	// printf("\"%s\" < \"\\t\\n\\200\\x41\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, "\t\n\200\x41", 10, check_len);
	// printf("\"%s\" < \"\\0\\0\\0\\0\\300\\300\\377\\377\\0\\0\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, "\0\0\0\0\300\300\377\377\0\0", 10, check_len);

	// /* big input */
	// int big_src[] = {511, 0xFFFE0201};
	// printf("\"%s\" < \"int[] {511, 0xFF}\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, big_src, 10, check_len);

	printf("\n↓leakcheck\n\n");
	while(1);
}
