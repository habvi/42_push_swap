#!/usr/bin/bash

leaks_args() {
    echo "|$@|"
    valgrind --log-file="valgrind.log" ./push_swap $@
    sleep 0.2
    python3 check_leaks.py
    echo "================================"
}

leaks() {
    sleep 0.2
    python3 check_leaks.py
    echo "================================"
}

# -----------------------------------------------------------------
make
echo "================================"

# -----------------------------------------------------------------
# error
leaks_args
leaks_args a
leaks_args a 5
leaks_args 4a
leaks_args -
leaks_args +
leaks_args + 5
leaks_args 2147483648
leaks_args -2147483649
leaks_args -2147483649 5
leaks_args 0 0
leaks_args -0 0
leaks_args -0 +0
leaks_args 0 +0
leaks_args 02 2
leaks_args 2 2
leaks_args 2 2 5
leaks_args 2 2 5 2

valgrind --log-file="valgrind.log" ./push_swap 02
leaks

# -----------------------------------------------------------------
# nothing happend
leaks_args 5
leaks_args -5 8
leaks_args -2147483648 0 2147483647

valgrind --log-file="valgrind.log" ./push_swap ""
leaks
valgrind --log-file="valgrind.log" ./push_swap " "
leaks
valgrind --log-file="valgrind.log" ./push_swap "" "  "
leaks
valgrind --log-file="valgrind.log" ./push_swap "" "  " 5
leaks
valgrind --log-file="valgrind.log" ./push_swap "    7"
leaks
valgrind --log-file="valgrind.log" ./push_swap "7      "
leaks
valgrind --log-file="valgrind.log" ./push_swap "  7      "
leaks

# -----------------------------------------------------------------
# ok
leaks_args 6 5

valgrind --log-file="valgrind.log" ./push_swap "  7   3   "
leaks
valgrind --log-file="valgrind.log" ./push_swap 5 "  7   3   "
leaks
valgrind --log-file="valgrind.log" ./push_swap "" "  " " 7 " "  -6  2 "  2147483647
leaks

# -----------------------------------------------------------------