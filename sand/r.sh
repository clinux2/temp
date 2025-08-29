find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i {} +

gcc -o ./bin/cli ./client/cli.c ./utils/*.c
gcc -o ./bin/serv ./server/serv.c