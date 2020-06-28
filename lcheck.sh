gcc -Wall -Werror -Wextra $1 -L . -lft
./a.out &
sleep 1
leaks $! | grep -E "leaks? for"
# leaks $!
kill $!
