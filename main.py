from collections import deque
from itertools import permutations
import sys
sys.setrecursionlimit(10 ** 7)
import time

OPS = ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
SA = 0
SB = 1
SS = 2
PA = 3
PB = 4
RA = 5
RB = 6
RR = 7
RRA = 8
RRB = 9
RRR = 10

RED = "red"
GREEN = "green"
color_dict = {"red" : "\033[31m",
              "green" : "\033[32m",
              "end" : "\033[0m"}

def print_color_str(color, text=""):
    print(color_dict[color] + text + color_dict["end"])

# ----------------------------------
def debug_a(A):
    print("stack A", A, file=sys.stderr)

def debug_b(B):
    print("stack B", B, file=sys.stderr)

def debug(A, B):
    debug_a(A)
    debug_b(B)

# ----------------------------------
def sa(A):
    if len(A) >= 2:
        A[0], A[1] = A[1], A[0]

def sb(B):
    if len(B) >= 2:
        B[0], B[1] = B[1], B[0]

def ss(A, B):
    sa(A)
    sb(B)

def pa(A, B):
    if B:
        A.appendleft(B.popleft())

def pb(A, B):
    if A:
        B.appendleft(A.popleft())

def ra(A):
    if len(A) >= 2:
        A.append(A.popleft())

def rb(B):
    if len(B) >= 2:
        B.append(B.popleft())

def rr(A, B):
    ra(A)
    rb(B)

def rra(A):
    if len(A) >= 2:
        A.appendleft(A.pop())

def rrb(B):
    if len(B) >= 2:
        B.appendleft(B.pop())

def rrr(A, B):
    rra(A)
    rrb(B)

# ----------------------------------
def is_stack_empty(A):
    return not len(A)

def is_executable_stack_size(A):
    return len(A) >= 2

# to do: optimize
def is_executable_op(A, B, i):
    if i == SA:
        return is_executable_stack_size(A)
    elif i == SB:
        return is_executable_stack_size(B)
    elif i == SS:
        return is_executable_stack_size(A) or is_executable_stack_size(B)
    elif i == PA:
        return not is_stack_empty(B)
    elif i == PB:
        return not is_stack_empty(A)
    elif i == RA:
        return is_executable_stack_size(A)
    elif i == RB:
        return is_executable_stack_size(B)
    elif i == RR:
        return is_executable_stack_size(A) or is_executable_stack_size(B)
    elif i == RRA:
        return is_executable_stack_size(A)
    elif i == RRB:
        return is_executable_stack_size(B)
    elif i == RRR:
        return is_executable_stack_size(A) or is_executable_stack_size(B)

def is_unnecessary_op(i, op):
    if not len(op):
        return False
    pre_op = OPS.index(op[-1])
    if i == SA:
        return pre_op in (SA, SB, SS)
    if i == SB:
        return pre_op in (SA, SB, SS)
    if i == SS:
        return pre_op in (SA, SB, SS)
    if i == PA:
        return pre_op == PB
    if i == PB:
        return pre_op == PA
    if i == RA:
        return pre_op in (RB, RRA, RRR)
    if i == RB:
        return pre_op in (RA, RRB, RRR)
    if i == RR:
        return pre_op in (RRA, RRB, RRR)
    if i == RRA:
        return pre_op in (RRB, RA, RR)
    if i == RRB:
        return pre_op in (RRA, RB, RR)
    if i == RRR:
        return pre_op in (RA, RB, RR)

def do_op(A, B, i):
    if i == SA: sa(A)
    elif i == SB: sb(B)
    elif i == SS: ss(A, B)
    elif i == PA: pa(A, B)
    elif i == PB: pb(A, B)
    elif i == RA: ra(A)
    elif i == RB: rb(B)
    elif i == RR: rr(A, B)
    elif i == RRA: rra(A)
    elif i == RRB: rrb(B)
    elif i == RRR: rrr(A, B)

def undo_op(A, B, i):
    if i == SA: sa(A)
    elif i == SB: sb(B)
    elif i == SS: ss(A, B)
    elif i == PA: pb(A, B)
    elif i == PB: pa(A, B)
    elif i == RA: rra(A)
    elif i == RB: rrb(B)
    elif i == RR: rrr(A, B)
    elif i == RRA: ra(A)
    elif i == RRB: rb(B)
    elif i == RRR: rr(A, B)

def dfs(A, B, op, sorted_a, ans, ans_len):
    if len(op) >= ans_len:
        return ans, ans_len
    if not len(B) and list(A) == sorted_a:
        ans = op.copy()
        ans_len = len(op)
        return ans, ans_len
    if len(op) == 8:
        return ans, ans_len
    for i in range(11):
        if is_executable_op(A, B, i) and not is_unnecessary_op(i, op):
            op.append(OPS[i])
            do_op(A, B, i)
            ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
            op.pop()
            undo_op(A, B, i)
    return ans, ans_len

# ----------------------------------
# 1 <= n <= 5
def all_n_pattern():
    n = int(sys.argv[1])
    for args in permutations(range(1, n + 1)):
        print("args:", *args)
        A = deque(args)
        B = deque([])

        start_time = time.time()
        ans = []
        ans_len = 2147483647
        op = []
        sorted_a = sorted(A)
        ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
        if not ans:
            print_color_str(RED, "[NO ANS..!!]")
        else:
            print(*ans, end=" ")
            print_color_str(GREEN, "[OK]")
        end_time = time.time()
        print("time:", end_time - start_time)
        print("================================", file=sys.stderr)

# ----------------------------------
# 1 <= n <= 5
def solve_less_than_6(A, B):
    start_time = time.time()
    ans = []
    ans_len = 2147483647
    op = []
    sorted_a = sorted(A)
    ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
    if not ans:
        print_color_str(RED, "[NO ANS..!!]")
    else:
        print(*ans, end=" ")
        print_color_str(GREEN, "[OK]")
    end_time = time.time()
    print("time:", end_time - start_time)
    print("================================", file=sys.stderr)

def stack_dfs(n):
    stack = [(1, n)]
    while stack:
        current_node = stack.pop()
        head, tail = current_node
        print(current_node)
        if head == tail:
            # --------------------------
            # post-order
            print(head)
            # --------------------------
            continue
        # --------------------------
        # pre-order
        total = tail - head + 1
        block_size = total // 3
        new_tail = head - 1
        for i in range(3):
            new_head = new_tail + 1
            new_tail = new_head + block_size - 1
            if total % 3 and i < total % 3:
                new_tail += 1
            if new_head > new_tail:
                continue
            stack.append((new_head, new_tail))
        # --------------------------

# n >= 6
def solve_over_6(n, A, B):
    stack_dfs(n)

# n >= 2
def command_line():
    n = len(sys.argv[1:])
    args = list(map(int, sys.argv[1:]))
    print(*args)
    A = deque(args)
    B = deque([])
    if n < 6:
        solve_less_than_6(A, B)
    else:
        solve_over_6(n, A, B)

# ----------------------------------
def main():
    argc = len(sys.argv)
    if argc == 2:
        all_n_pattern()
    else:
        command_line()

if __name__=="__main__":
    main()


'''
n = 5
3 4 2 1 5 : 3.8s
4 1 3 2 5 : 3.6s
4 3 2 1 5 : 6.7s
'''