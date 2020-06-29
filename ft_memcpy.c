#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "libft.h"

void test(void *org_dst, void *ft_dst, void *src, int len, int check_len)
{
	printf("\"%s\" < \"%s\" len:%d\n", org_dst, src, len);
	void* org_rtn = memcpy(org_dst, src, len);
	// void* ft_rtn = memcpy(src, c, len);
	// void* org_rtn = ft_memcpy(src, c, len);
	void* ft_rtn = ft_memcpy(ft_dst, src, len);

	int dif = memcmp(org_rtn, ft_rtn, check_len);
	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("cmp => %d\n", dif);
	printf("org: \"%s\"\n", org_rtn);
	printf("ft : \"%s\"\n", ft_rtn);
	printf(RESET);
}

void special_test(void *org_dst, void *ft_dst, void *src, int len, int check_len)
{
	void* org_rtn = memcpy(org_dst, src, len);
	// void* ft_rtn = memcpy(src, c, len);
	// void* org_rtn = ft_memcpy(src, c, len);
	void* ft_rtn = ft_memcpy(ft_dst, src, len);
	int dif = memcmp(org_rtn, ft_rtn, check_len);
	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("cmp => %d\n", dif);
	printf("print ascii.\n");
	printf("org: ");
	for (size_t i = 0; i < (size_t)check_len; i++)
	{
		printf("%d ", ((unsigned char*)org_rtn)[i]);
	}
	printf("\nft : ");
	for (size_t i = 0; i < (size_t)check_len; i++)
	{
		printf("%d ", ((unsigned char*)ft_rtn)[i]);
	}
	printf("\n"RESET);
}

int main(void)
{
	char src[] = "abcdefgh";
	char org_dst[20];
	ft_memset(org_dst, 0, 10);
	char ft_dst[10];
	ft_memset(ft_dst, 0, 10);
	int check_len = 10;
	printf("== standard check ==\n");
	test(org_dst, ft_dst, src, 0, check_len);
	test(org_dst, ft_dst, src, 1, check_len);
	test(org_dst, ft_dst, src, 8, check_len);
	test(org_dst, ft_dst, src, 10, check_len);

	printf("\n== unusual check ==\n");
	/* special character */
	printf("> special character check <\n");
	printf("\"%s\" < \"\\t\\n\\200\\x41\" len:%d\n", org_dst, 10);
	special_test(org_dst, ft_dst, "\t\n\200\x41", 10, check_len);
	printf("\"%s\" < \"\\0\\0\\0\\0\\300\\300\\377\\377\\0\\0\" len:%d\n", org_dst, 10);
	special_test(org_dst, ft_dst, "\0\0\0\0\300\300\377\377\0\0", 10, check_len);

	/* big input */
	int big_src[] = {511, 0xFFFE0201};
	printf("\"%s\" < \"int[] {511, 0xFF}\" len:%d\n", org_dst, 10);
	special_test(org_dst, ft_dst, big_src, 10, check_len);

	printf("\n↓leakcheck\n\n");
	while(1);
}
