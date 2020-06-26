#include <string.h>
#include <stdio.h>
#include "test.h"
#include "../Libft/libft.h"

void test(char *s1, char *s2, int size)
{
	printf("n = %d\n", size);
	int org_rtn = memcmp(s1,s2,size+1);
	int ft_rtn = ft_memcmp(s1,s2,size+1);

	org_rtn == ft_rtn ? printf(GREEN) : printf(RED);
	printf("memcmp()   =>%d\n", org_rtn);
	printf("ft_memcmp()=>%d\n", ft_rtn);
	printf(RESET);
}

int		main(void)
{
	char str1[] = "HelloWorld!!!!!";
	char *str2[] = {
		"HelloWorld!",
		"Hello",
		"helloworld",
		"",
		NULL
	};
	size_t size[] = {
		0, 5, 10, 15, 20, 555
	};

	int i = 0;
	while (str2[i])
	{
		printf("------------------\n");
		printf("str1: %s\nstr2: %s\n", str1,str2[i]);
		printf("------------------\n");
		int j = 0;
		while (size[j] != 555)
		{
			test(str1, str2[i], size[j]);
			j++;
		}
		i++;
	}

	printf("------------------\n");
	printf("      error       \n");
	printf("------------------\n");
	printf("test\\200, test\\0\n");
	test("test\200", "test\0", 6);

	printf("\n↓leakcheck\n\n");
	while(1);
}
