LIBFT_PATH=../Libft
gcc -Wall -Werror -Wextra ft_$1.c -L${LIBFT_PATH} -lft -I${LIBFT_PATH}
if [ $? -eq 0 ] ; then
	./a.out &
	sleep 1
	leaks $! | grep -E "leaks? for"
	kill $!
fi
