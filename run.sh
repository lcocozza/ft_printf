#/bin/zsh

clear
make
gcc -Wall -Werror -Wextra  main.c -I includes/ libftprintf.a -g3 -fsanitize=address
./a.out

