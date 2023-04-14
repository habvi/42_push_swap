import sys
from collections import deque
sys.setrecursionlimit(10 ** 7)

# ----------------------------------
def debug_a():
    print("stack A", A)

def debug_b():
    print("stack B", B)

def debug():
    debug_a()
    debug_b()
    print()

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
args = list(map(int, sys.argv[1:]))
A = deque(args)
B = deque([])
debug()

# ----------------------------------
def is_stack_empty(A):
    return not len(A)

def is_stack_a_size_more_than_2(A):
    return len(A) >= 2

def is_stack_b_size_more_than_2(B):
    return len(B) >= 2

def is_move_ok(A, B, i):
    if i == 0:
        return is_stack_a_size_more_than_2(A)
    elif i == 1:
        return is_stack_b_size_more_than_2(B)
    elif i == 2:
        return is_stack_a_size_more_than_2(A) or is_stack_b_size_more_than_2(B)
    elif i == 3:
        return not is_stack_empty(B)
    elif i == 4:
        return not is_stack_empty(A)
    elif i == 5:
        return is_stack_a_size_more_than_2(A)
    elif i == 6:
        return is_stack_b_size_more_than_2(B)
    elif i == 7:
        return is_stack_a_size_more_than_2(A) or is_stack_b_size_more_than_2(B)
    elif i == 8:
        return is_stack_a_size_more_than_2(A)
    elif i == 9:
        return is_stack_b_size_more_than_2(B)
    elif i == 10:
        return is_stack_a_size_more_than_2(A) or is_stack_b_size_more_than_2(B)

def do_op(A, B, i):
    if i == 0: sa(A)
    elif i == 1: sb(B)
    elif i == 2: ss(A, B)
    elif i == 3: pa(A, B)
    elif i == 4: pb(A, B)
    elif i == 5: ra(A)
    elif i == 6: rb(B)
    elif i == 7: rr(A, B)
    elif i == 8: rra(A)
    elif i == 9: rrb(B)
    elif i == 10: rrr(A, B)

def redo_op(A, B, i):
    if i == 0: sa(A)
    elif i == 1: sb(B)
    elif i == 2: ss(A, B)
    elif i == 3: pb(A, B)
    elif i == 4: pa(A, B)
    elif i == 5: rra(A)
    elif i == 6: rrb(B)
    elif i == 7: rrr(A, B)
    elif i == 8: ra(A)
    elif i == 9: rb(B)
    elif i == 10: rr(A, B)

def dfs(A, B, op, i):
    global ans, ans_len
    if list(A) == sorted_a:
        if len(op) < ans_len:
            print("op:", op)
            debug()
            ans = op.copy()
            ans_len = len(op)
        return
    if len(op) == 7:
        return
    for i in range(11):
        if is_move_ok(A, B, i):
            op.append(ops[i])
            do_op(A, B, i)
            dfs(A, B, op, i)
            op.pop()
            redo_op(A, B, i)

ans = []
ans_len = 2147483647
ops = ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
op = []
sorted_a = sorted(A)
dfs(A, B, op, -1)
print("ans:", ans)