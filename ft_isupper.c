#include <stdio.h>
#include <ctype.h>
#include "test.h"
#include "libft.h"

void test(char *str){
	int i = 0;
	while (str[i])
	{
		int rtn = ft_isupper(str[i]);
		int rtn_org = isupper(str[i]);
		(rtn == rtn_org) ? printf(GREEN) : printf(RED);
		printf("%c"RESET, str[i]);
		i++;
	}
}

int	main(void){
	char *valid_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *invalid_case = " !\"#%%&'()*+,-./0123456789:;<=>?@[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // \a\b\f\n\r\t\v
	printf("valid case:");
	test(valid_case);
	printf("\ninvalid case:");
	test(invalid_case);
	printf("\n↓leakcheck\n\n");
	while(1);
}
