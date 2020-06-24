#include <stdio.h>
#include <ctype.h>
#include "test.h"
#include "../ft_tolower.c"
#include "../ft_isupper.c"


void test(char *str){
	int i = 0;
	while (str[i])
	{
		int rtn = ft_tolower(str[i]);
		int rtn_org = tolower(str[i]);
		(rtn_org != str[i]) ? printf(BOLD) : 0;
		(rtn == rtn_org) ? printf(GREEN) : printf(RED);
		printf("%c"RESET, rtn);
		i++;
	}
	printf("\n");
}

void test_int(int num){
	int rtn = ft_tolower(num);
	int rtn_org = tolower(num);
	(rtn_org != num) ? printf(BOLD) : 0;
	(rtn == rtn_org) ? printf(GREEN) : printf(RED);
	printf("%d\n"RESET, rtn);
}

int	main(void){
	printf("usual case:");
	char *test_case = " !\"#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // \a\b\f\n\r\t\v
	test(test_case);
	printf("unusual case:\n");
	int invalid_case[] = {-1, 8, 48, 65, 97, 256, 1000};
	int i = 0;
	while (i < 7){
		test_int(invalid_case[i]);
		i++;
	}
}
