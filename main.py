from collections import deque
from itertools import permutations
import sys
sys.setrecursionlimit(10 ** 7)

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
        # print("op:", op)
        # debug(A, B)
        ans = op.copy()
        ans_len = len(op)
        return ans, ans_len
    if len(op) == 8:
        return ans, ans_len
    for i in range(11):
        if is_executable_op(A, B, i):
            op.append(OPS[i])
            do_op(A, B, i)
            ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
            op.pop()
            undo_op(A, B, i)
    return ans, ans_len

# ----------------------------------
def command_line(ans, ans_len, op):
    args = list(map(int, sys.argv[1:]))
    print(*args)
    A = deque(args)
    B = deque([])
    debug(A, B)

    sorted_a = sorted(A)
    ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
    print(*ans)
    print("================================", file=sys.stderr)

# n: 2-6
def all_n_pattern(ans, ans_len, op):
    n = int(sys.argv[1])
    if n > 6:
        return
    for args in permutations(range(1, n)):
        print(*args)
        A = deque(args)
        B = deque([])
        debug(A, B)

        sorted_a = sorted(A)
        ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
        print(*ans)
        print("================================", file=sys.stderr)

def main():
    argc = len(sys.argv)
    ans = []
    ans_len = 2147483647
    op = []
    if argc == 2:
        all_n_pattern(ans, ans_len, op)
    else:
        command_line(ans, ans_len, op)

if __name__=="__main__":
    main()