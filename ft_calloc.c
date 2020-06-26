#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "test.h"
#include "../Libft/libft.h"

void test(size_t count, size_t size)
{
	void *org_rtn = calloc(count, size);
	// void *ft_rtn = calloc(count, size);
	void *ft_rtn = ft_calloc(count, size);

	printf("> count:%zu, size:%zu\n", count, size);
	if (size == 0)
	{
		// (org_rtn == ft_rtn) ? printf(GREEN) : printf(RED);
		printf("org: (%p)\n", org_rtn);
		printf("ft : (%p)\n", ft_rtn);
	}
	else if (size == sizeof(char))
	{
		int dif = ft_strncmp((char *)org_rtn, (char *)ft_rtn, count);
		(dif == 0) ? printf(GREEN) : printf(RED);
		printf("org: (%p) %s\n", org_rtn, org_rtn);
		printf("ft : (%p) %s\n", ft_rtn, ft_rtn);
	}
	else if (size == sizeof(int))
	{
		int dif = ft_memcmp((int *)org_rtn, (int *)ft_rtn, count);
		(dif == 0) ? printf(GREEN) : printf(RED);
		size_t i = 0;
		printf("org: (%p)", org_rtn);
		while (i < count*4)
		{
			printf("%d ", ((int *)org_rtn)[i]);
			i++;
		}
		i = 0;
		printf("\nft : (%p)", ft_rtn);
		while (i < count*4)
		{
			printf("%d ", ((int *)ft_rtn)[i]);
			i++;
		}
	}
	printf("\n"RESET);
	free(org_rtn);
	free(ft_rtn);
	// (org_rtn == ft_rtn) ? printf(GREEN) : printf(RED);
	// printf("org: %d\n", org_rtn);
	// printf("ft : %d\n", ft_rtn);
	// printf(RESET);
}

// void advanced_test(size_t count, size_t size)
// {
// 	void *org_rtn = calloc(count, size);
// 	// int ft_rtn = calloc(count, size);
// 	void *ft_rtn = ft_calloc(count, size);

// 	// (org_rtn == ft_rtn) ? printf(GREEN) : printf(RED);
// 	printf("> count:%zu, size:%zu\n", count, size);
// 	// printf("org: %d\n", org_rtn);
// 	// printf("ft : %d\n", ft_rtn);
// 	// printf(RESET);
// }

int main(void)
{
	printf("== basic input ==\n");
	test(10, sizeof(char));
	test(5, sizeof(int));

	printf("\n== advanced input ==\n");
	test(0, sizeof(char));
	test(10, 0);
	test(0, 0);

	printf("\n↓leakcheck\n\n");
	while(1);
}
