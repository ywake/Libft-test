#include <stdio.h>
#include <ctype.h>
#include "./test.h"
#include "../Libft/ft_isalnum.c"
#include "../Libft/ft_isalpha.c"
#include "../Libft/ft_isdigit.c"
#include "../Libft/ft_islower.c"
#include "../Libft/ft_isupper.c"

void test(char *str){
	int i = 0;
	while (str[i])
	{
		int rtn = ft_isalnum(str[i]);
		int rtn_org = isalnum(str[i]);
		(rtn_org == 1) ? printf(BOLD) : 0;
		(rtn == rtn_org) ? printf(GREEN) : printf(RED);
		printf("%c"RESET, str[i]);
		i++;
	}
	printf("\n");
}

void test_int(int num){
	int rtn = ft_isalnum(num);
	int rtn_org = isalnum(num);
	(rtn_org == 1) ? printf(BOLD) : 0;
	(rtn == rtn_org) ? printf(GREEN) : printf(RED);
	printf("%d\n"RESET, num);
}

int	main(void){
	printf("usual case:");
	char *test_case = " !\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // \a\b\f\n\r\t\v
	test(test_case);
	printf("unusual case:\n");
	int invalid_case[] = {-1,48, 65, 256, 1000};
	int i = 0;
	while (i < 5){
		test_int(invalid_case[i]);
		i++;
	}
}
