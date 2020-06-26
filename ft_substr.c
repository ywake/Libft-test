#include <stdio.h>
#include <string.h>
#include "test.h"
#include "../Libft/libft.h"

void	test(char *src, unsigned int start, size_t len)
{
	printf("> src:\"%s\" start:%u len:%zu\n", src, start, len);
	char	*ft_rtn = ft_substr(src, start, len);
	printf("\"%s\"\n", ft_rtn);
	free(ft_rtn);
}

int		main(void)
{
	printf("== basic input ==\n");
	test("this is test", 5, 2);
	test("this is test", 5, 7);

	printf("\n== advanced input ==\n");
	test("this is test", 5, 20);
	test("this is test", 20, 5);
	test("", 5, 3);
	// test(NULL, 5, 3); -> seg fault
	test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
