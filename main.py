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

STACK_A_HEAD = 1
STACK_A_TAIL = 2
STACK_B_HEAD = 3
STACK_B_TAIL = 4

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
def sa(op, A):
    if len(A) >= 2:
        A[0], A[1] = A[1], A[0]
        op.append(OPS[SA])
    return op, A

def sb(op, B):
    if len(B) >= 2:
        B[0], B[1] = B[1], B[0]
        op.append(OPS[SB])
    return op, B

def ss(op, A, B):
    op, A = sa(op, A)
    op, B = sb(op, B)
    return op, A, B

def pa(op, A, B):
    if B:
        A.appendleft(B.popleft())
        op.append(OPS[PA])
    return op, A, B

def pb(op, A, B):
    if A:
        B.appendleft(A.popleft())
        op.append(OPS[PB])
    return op, A, B

def ra(op, A):
    if len(A) >= 2:
        A.append(A.popleft())
        op.append(OPS[RA])
    return op, A

def rb(op, B):
    if len(B) >= 2:
        B.append(B.popleft())
        op.append(OPS[RB])
    return op, B

def rr(op, A, B):
    op, A = ra(op, A)
    op, B = rb(op, B)
    return op, A, B

def rra(op, A):
    if len(A) >= 2:
        A.appendleft(A.pop())
        op.append(OPS[RRA])
    return op, A

def rrb(op, B):
    if len(B) >= 2:
        B.appendleft(B.pop())
        op.append(OPS[RRB])
    return op, B

def rrr(op, A, B):
    op, A = rra(op, A)
    op, B = rrb(op, B)
    return op, A, B

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

def do_op(op, A, B, i):
    if i == SA: sa(op, A)
    elif i == SB: sb(op, B)
    elif i == SS: ss(op, A, B)
    elif i == PA: pa(op, A, B)
    elif i == PB: pb(op, A, B)
    elif i == RA: ra(op, A)
    elif i == RB: rb(op, B)
    elif i == RR: rr(op, A, B)
    elif i == RRA: rra(op, A)
    elif i == RRB: rrb(op, B)
    elif i == RRR: rrr(op, A, B)

def undo_op(op, A, B, i):
    if i == SA: sa(op, A)
    elif i == SB: sb(op, B)
    elif i == SS: ss(op, A, B)
    elif i == PA: pb(op, A, B)
    elif i == PB: pa(op, A, B)
    elif i == RA: rra(op, A)
    elif i == RB: rrb(op, B)
    elif i == RR: rrr(op, A, B)
    elif i == RRA: ra(op, A)
    elif i == RRB: rb(op, B)
    elif i == RRR: rr(op, A, B)

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
            do_op([], A, B, i)
            ans, ans_len = dfs(A, B, op, sorted_a, ans, ans_len)
            op.pop()
            undo_op([], A, B, i)
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

# ----------------------------------
def find_the_block_place(A, B, mn, mx):
    if A:
        if mn <= A[0] <= mx:
            return STACK_A_HEAD
        if mn <= A[-1] <= mx:
            return STACK_A_TAIL
    if B:
        if mn <= B[0] <= mx:
            return STACK_B_HEAD
        elif mn <= B[-1] <= mx:
            return STACK_B_TAIL

def move_sorted_from_large_num(A, B, op, head):
    stack_place = find_the_block_place(A, B, head, head)
    if stack_place == STACK_A_HEAD:
        pass
    elif stack_place == STACK_A_TAIL:
        op, A = rra(op, A)
    elif stack_place == STACK_B_HEAD:
        op, A, B = pa(op, A, B)
    elif stack_place == STACK_B_TAIL:
        op, B = rrb(op, B)
        op, A, B = pa(op, A, B)
    return A, B, op

def is_num_in_move_range(A, B, stack_place, mn, mx):
    if stack_place == STACK_A_HEAD:
        return mn <= A[0] <= mx
    if stack_place == STACK_A_TAIL:
        return mn <= A[-1] <= mx
    if stack_place == STACK_B_HEAD:
        return mn <= B[0] <= mx
    if stack_place == STACK_B_TAIL:
        return mn <= B[-1] <= mx

def get_move_num(A, B, stack_place):
    if stack_place == STACK_A_HEAD:
        return A[0]
    if stack_place == STACK_A_TAIL:
        return A[-1]
    if stack_place == STACK_B_HEAD:
        return B[0]
    if stack_place == STACK_B_TAIL:
        return B[-1]

# use pointer to func
def move_num(A, B, op, before_place, after_place):
    if before_place == STACK_A_HEAD:
        if after_place == STACK_A_TAIL:
            op, A = ra(op, A)
        elif after_place == STACK_B_HEAD:
            op, A, B = pb(op, A, B)
        elif after_place == STACK_B_TAIL:
            op, A, B = pb(op, A, B)
            op, B = rb(op, B)
    elif before_place == STACK_A_TAIL:
        if after_place == STACK_A_HEAD:
            op, A = rra(op, A)
        elif after_place == STACK_B_HEAD:
            op, A = rra(op, A)
            op, A, B = pb(op, A, B)
        elif after_place == STACK_B_TAIL:
            op, A = rra(op, A)
            op, A, B = pb(op, A, B)
            op, B = rb(op, B)
    elif before_place == STACK_B_HEAD:
        if after_place == STACK_A_HEAD:
            op, A, B = pa(op, A, B)
        elif after_place == STACK_A_TAIL:
            op, A, B = pa(op, A, B)
            op, A = ra(op, A)
        elif after_place == STACK_B_TAIL:
            op, B = rb(op, B)
    elif before_place == STACK_B_TAIL:
        if after_place == STACK_A_HEAD:
            op, B = rrb(op, B)
            op, A, B = pa(op, A, B)
        elif after_place == STACK_A_TAIL:
            op, B = rrb(op, B)
            op, A, B = pa(op, A, B)
            op, A = ra(op, A)
        elif after_place == STACK_B_HEAD:
            op, B = rrb(op, B)
    return A, B, op

def move_to_divide_nums(A, B, op, head, tail, stack_place, movable_stack_place, nums_range_per_block):
    total = tail - head + 1
    # if total <= 3:
    # else:
    for i in range(total):
        num = get_move_num(A, B, stack_place)
        m = len(nums_range_per_block)
        for i in range(m):
            mn, mx = nums_range_per_block[m - i - 1]
            if mn <= num <= mx:
                A, B, op = move_num(A, B, op, stack_place, movable_stack_place[i])
                break
    return A, B, op

def divide_nums_to_other_stacks(stack, A, B, op, head, tail):
    stack_place = find_the_block_place(A, B, head, tail)
    movable_stack_place = []
    for i in range(1, 5):
        if i != stack_place:
            movable_stack_place.append(i)

    total = tail - head + 1
    block_size = total // 3
    new_tail = head - 1
    nums_range_per_block = []
    for i in range(3):
        new_head = new_tail + 1
        new_tail = new_head + block_size - 1
        if total % 3 and i < total % 3:
            new_tail += 1
        if new_head > new_tail:
            continue
        stack.append((new_head, new_tail))
        nums_range_per_block.append((new_head, new_tail))
    A, B, op = move_to_divide_nums(A, B, op, head, tail, stack_place, movable_stack_place, nums_range_per_block)
    return stack, A, B, op

def stack_dfs(n, A, B, op):
    stack = [(1, n)]
    while stack:
        current_node = stack.pop()
        head, tail = current_node
        if head == tail:
            A, B, op = move_sorted_from_large_num(A, B, op, head)
            continue
        stack, A, B, op = divide_nums_to_other_stacks(stack, A, B, op, head, tail)
    return A, op

# n >= 6
def solve_over_6(n, A, B):
    start_time = time.time()
    sorted_a = sorted(A)
    op = []
    A, op = stack_dfs(n, A, B, op)
    if not op:
        print_color_str(RED, "[NO ANS..!!]")
    else:
        print(*op)
        print("op_len:", len(op))
        if list(A) == sorted_a:
            print_color_str(GREEN, "[OK]")
        else:
            print_color_str(RED, "[KO]")
    end_time = time.time()
    print("time:", end_time - start_time)
    print("================================", file=sys.stderr)

# ----------------------------------
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
python3 main.py $(python3 -c 'import random; print(*random.sample(range(1, 101), 100))')
python3 main.py $(python3 -c 'import random; print(*random.sample(range(1, 501), 500))')
'''