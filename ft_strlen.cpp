#include <gtest/gtest.h>
#include <cstring>

extern "C"
{
#include "libft.h"
}

TEST(part00, ft_strlen)
{
	char *test[] = {
		"test",
		"55555",
		"88888888",
		"999999999",
		"supercalifragilisticexpialidocious",
		"",
		"あいうえお",
		NULL
	};
	int i = 0;
	while (test[i])
	{
		EXPECT_EQ(strlen(test[i]), ft_strlen(test[i]));
		i++;
	}
}
