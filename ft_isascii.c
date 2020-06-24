#include <stdio.h>
#include <ctype.h>
#include "./test.h"
#include "../Libft/ft_isascii.c"

void test(char *str){
	int i = 0;
	while (str[i])
	{
		int rtn = ft_isascii(str[i]);
		int rtn_org = isascii(str[i]);
		(rtn_org == 1) ? printf(BOLD) : 0;
		(rtn == rtn_org) ? printf(GREEN) : printf(RED);
		printf("%c"RESET, str[i]);
		i++;
	}
	printf("\n");
}

void test_int(int num){
	int rtn = ft_isascii(num);
	int rtn_org = isascii(num);
	(rtn_org == 1) ? printf(BOLD) : 0;
	(rtn == rtn_org) ? printf(GREEN) : printf(RED);
	printf("%d\n"RESET, num);
}

int	main(void){
	printf("usual case:");
	char *test_case = " !\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // \a\b\f\n\r\t\v
	test(test_case);
	printf("unusual case:\n");
	int invalid_case[] = {-1, 8, 48, 65, 256, 1000};
	int i = 0;
	while (i < 6){
		test_int(invalid_case[i]);
		i++;
	}
}
