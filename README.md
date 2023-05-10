# push_swap
Sort integers using 2 stacks (a & b) in minimum operations with the least number of moves possible.

[visualizer](https://github.com/o-reo/push_swap_visualizer)
![](image/push_swap_100_20230507.gif)

<br>

Usage
```shell
# push_swap
$ make
$ ./push_swap 2 -5 10 7

# checker
$ make bonus
$ ARG="2 -5 10 7"; ./push_swap $ARG | ./checker $ARG
```

<br>

operations  
- sa : swap a
- sb : swap b
- ss : swap a & swap b
- pa : push a
- pb : push b
- ra : rotate a
- rb : rotate b
- rr : rotate a & rotate b
- rra : reverse rotate a
- rrb : reverse rotate b
- rrr : reverse rotate a & reverse rotate b

<br>

External functions
- read, write
- malloc, free