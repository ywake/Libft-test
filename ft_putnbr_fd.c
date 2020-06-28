#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "test.h"
#include "../Libft/libft.h"
// #include "../Libft/ft_putnbr_fd.c"

void	test(int n, int fd)
{
	printf("> `%d`\n", n);
	ft_putnbr_fd(n, fd);
	printf("\n");
	// int dif = ft_strncmp(expect, rtn, ft_strlen(expect + 1));
	// dif == 0 ? printf(GREEN) : printf(BOLDRED);
	// printf("    expect: \"%s\"\n", expect);
	// printf("ft_putchar_fd: \"%s\"\n", rtn);
	// printf(RESET);
}

int		main(void)
{
	printf("== basic input ==\n");
	test(0, 1);
	test(1, 1);
	test(-100, 1);
	test(INT_MAX, 1);
	test(INT_MIN, 1);
	// test('\n', 1);
	// int fd = open("./out_ft_puchar_fd", O_RDWR);
	// test('A', fd);
	// close(fd);

	// printf("\n== advanced input ==\n");
	// test("this is test", 5, 20);
	// test("this is test", 20, 5);
	// test("", 5, 3);
	// // test(NULL, 5, 3); -> seg fault
	// test("\200\t\x41\0", 0, 4);

	printf("\n↓leakcheck\n\n");
	while(1);
}
