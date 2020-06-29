#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "libft.h"

void test(void *org_dst, void *org_src, void *ft_dst, void *ft_src, int len)
{
	size_t check_len = 20;
	printf("\"%s\" < \"%s\" len:%d\n", org_dst, org_src, len);
	void* org_rtn = memmove(org_dst, org_src, len);
	void* ft_rtn = ft_memmove(ft_dst, ft_src, len);

	int dif = memcmp(org_rtn, ft_rtn, len);
	(dif == 0) ? printf(GREEN) : printf(BOLDRED);
	printf("cmp => %d\n", dif);
	printf("org: \"%s\"\n", org_rtn);
	printf("org: ");
	for (size_t i = 0; i < check_len; i++)
	{
		printf("%d ", ((unsigned char*)org_rtn)[i]);
	}
	printf("\nft : \"%s\"\n", ft_rtn);
	printf("ft : ");
	for (size_t i = 0; i < check_len; i++)
	{
		printf("%d ", ((unsigned char*)ft_rtn)[i]);
	}
	printf("\n"RESET);
}

int main(void)
{
	char buf[10] = "BBBBBBBBB";
	buf[4] = 'B';
	char org_src[6] = "abcde";
	char org_dst[10];
	char buf1[10] = "BBBBBBBBB";
	buf1[4] = 'B';
	char ft_src[6] = "abcde";
	char ft_dst[10];
	ft_memset(org_dst, 0, 10);
	ft_memset(ft_dst, 0, 10);
	printf("== standard check ==\n");
	test(org_dst, org_src, ft_dst, ft_src, 0);
	test(org_dst, org_src, ft_dst, ft_src, 1);
	test(org_dst, org_src, ft_dst, ft_src, 3);
	test(org_dst, org_src, ft_dst, ft_src, 8);
	test(org_dst, org_src, ft_dst, ft_src, 10);
	test(org_dst, org_src, ft_dst, ft_src, 15);

	printf("\n== unusual check ==\n");
	printf("> backwards check <\n");
	char dummy[50];
	ft_memset(dummy, 0, 50);
	char org_dst_b[10];
	char org_src_b[6] = "abcde";
	char dummy1[50];
	ft_memset(dummy1, 0, 50);
	char ft_dst_b[10];
	char ft_src_b[6] = "abcde";
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 0);
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 1);
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 3);
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 8);
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 10);
	ft_memset(org_dst_b, 0, 10);
	ft_memset(ft_dst_b, 0, 10);
	test(org_dst_b, org_src_b, ft_dst_b, ft_src_b, 15);
	/* special character */
	// printf("> special character check <\n");
	// printf("\"%s\" < \"\\t\\n\\200\\x41\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, "\t\n\200\x41", 10);
	// printf("\"%s\" < \"\\0\\0\\0\\0\\300\\300\\377\\377\\0\\0\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, "\0\0\0\0\300\300\377\377\0\0", 10);

	/* big input */
	// int big_src[] = {511, 0xFFFE0201};
	// printf("\"%s\" < \"int[] {511, 0xFF}\" len:%d\n", org_dst, 10);
	// special_test(org_dst, ft_dst, big_src, 10);

	printf("\n↓leakcheck\n\n");
	while(1);
}
