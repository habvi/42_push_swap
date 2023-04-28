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

# 3 or 4
LAST_BLOCK_SIZE = 4

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

def is_unnecessary_compare_pre_op(i, op):
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
    if i == SA:
        op, A = sa(op, A)
    elif i == SB:
        op, B = sb(op, B)
    elif i == SS:
        op, A, B = ss(op, A, B)
    elif i == PA:
        op, A, B = pa(op, A, B)
    elif i == PB:
        op, A, B = pb(op, A, B)
    elif i == RA:
        op, A = ra(op, A)
    elif i == RB:
        op, B = rb(op, B)
    elif i == RR:
        op, A, B = rr(op, A, B)
    elif i == RRA:
        op, A = rra(op, A)
    elif i == RRB:
        op, B = rrb(op, B)
    elif i == RRR:
        op, A, B = rrr(op, A, B)
    return A, B, op

def undo_op(op, A, B, i):
    if i == SA:
        op, A = sa(op, A)
    elif i == SB:
        op, B = sb(op, B)
    elif i == SS:
        op, A, B = ss(op, A, B)
    elif i == PA:
        op, A, B = pb(op, A, B)
    elif i == PB:
        op, A, B = pa(op, A, B)
    elif i == RA:
        op, A = rra(op, A)
    elif i == RB:
        op, B = rrb(op, B)
    elif i == RR:
        op, A, B = rrr(op, A, B)
    elif i == RRA:
        op, A = ra(op, A)
    elif i == RRB:
        op, B = rb(op, B)
    elif i == RRR:
        op, A, B = rr(op, A, B)
    return A, B, op

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
        if is_executable_op(A, B, i) and not is_unnecessary_compare_pre_op(i, op):
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
            print(*ans)
            print(len(ans))
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
        print(*ans)
        print(len(ans))
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

# ----------------------------------
# idx: 0 or 1
def is_num_in_range(stack_place, idx, head, tail, A, B):
    if stack_place == STACK_A_HEAD:
        return head <= A[idx] <= tail
    if stack_place == STACK_A_TAIL:
        return head <= A[-1] <= tail
    if stack_place == STACK_B_HEAD:
        return head <= B[idx] <= tail
    if stack_place == STACK_B_TAIL:
        return head <= B[-1] <= tail

def is_in_range_for_sa(A, B, head, tail):
    if not is_num_in_range(STACK_A_HEAD, 0, head, tail, A, B):
        return True
    if not is_num_in_range(STACK_A_HEAD, 1, head, tail, A, B):
        return True
    return False

def is_in_range_for_sb(A, B, head, tail):
    if not is_num_in_range(STACK_B_HEAD, 0, head, tail, A, B):
        return True
    if not is_num_in_range(STACK_B_HEAD, 1, head, tail, A, B):
        return True
    return False

def is_in_range_for_ss(A, B, head, tail):
    if is_executable_stack_size(A) and is_executable_stack_size(B):
        if is_in_range_for_sa(A, B, head, tail):
            return True
        if is_in_range_for_sb(A, B, head, tail):
            return True
        return False
    if is_executable_stack_size(A):
        return is_in_range_for_sa(A, B, head, tail)
    if is_executable_stack_size(B):
        return is_in_range_for_sb(A, B, head, tail)
    return False

def is_in_range_for_pa(A, B, head, tail):
    return not is_num_in_range(STACK_B_HEAD, 0, head, tail, A, B)

def is_in_range_for_pb(A, B, head, tail):
    return not is_num_in_range(STACK_A_HEAD, 0, head, tail, A, B)

def is_in_range_for_ra(A, B, head, tail):
    return not is_num_in_range(STACK_A_HEAD, 0, head, tail, A, B)

def is_in_range_for_rb(A, B, head, tail):
    return not is_num_in_range(STACK_B_HEAD, 0, head, tail, A, B)

def is_in_range_for_rr(A, B, head, tail):
    if not is_stack_empty(A) and not is_stack_empty(B):
        if is_in_range_for_ra(A, B, head, tail):
            return True
        if is_in_range_for_rb(A, B, head, tail):
            return True
        return False
    if not is_stack_empty(A):
        return is_in_range_for_ra(A, B, head, tail)
    if not is_stack_empty(B):
        return is_in_range_for_rb(A, B, head, tail)
    return False

def is_in_range_for_rra(A, B, head, tail):
    return not is_num_in_range(STACK_A_TAIL, 0, head, tail, A, B)

def is_in_range_for_rrb(A, B, head, tail):
    return not is_num_in_range(STACK_B_TAIL, 0, head, tail, A, B)

def is_in_range_for_rrr(A, B, head, tail):
    if not is_stack_empty(A) and not is_stack_empty(B):
        if is_in_range_for_rra(A, B, head, tail):
            return True
        if is_in_range_for_rrb(A, B, head, tail):
            return True
        return False
    if not is_stack_empty(A):
        return is_in_range_for_rra(A, B, head, tail)
    if not is_stack_empty(B):
        return is_in_range_for_rrb(A, B, head, tail)
    return False

def is_num_out_of_block_range(A, B, i, head, tail):
    if i == SA:
        return is_in_range_for_sa(A, B, head, tail)
    if i == SB:
        return is_in_range_for_sb(A, B, head, tail)
    if i == SS:
        return is_in_range_for_ss(A, B, head, tail)
    if i == PA:
        return is_in_range_for_pa(A, B, head, tail)
    if i == PB:
        return is_in_range_for_pb(A, B, head, tail)
    if i == RA:
        return is_in_range_for_ra(A, B, head, tail)
    if i == RB:
        return is_in_range_for_rb(A, B, head, tail)
    if i == RR:
        return is_in_range_for_rr(A, B, head, tail)
    if i == RRA:
        return is_in_range_for_rra(A, B, head, tail)
    if i == RRB:
        return is_in_range_for_rrb(A, B, head, tail)
    if i == RRR:
        return is_in_range_for_rrr(A, B, head, tail)

def is_unnecessary_op(A, B, i, tmp_op, head, tail):
    if not is_executable_op(A, B, i):
        return True
    if is_unnecessary_compare_pre_op(i, tmp_op):
        return True
    if is_num_out_of_block_range(A, B, i, head, tail):
        return True
    return False

def dfs_between_stack(A, B, head, tail, sorted_num, tmp_op, ans, ans_len):
    total = tail - head + 1
    if len(tmp_op) >= ans_len:
        return ans, ans_len
    if list(A)[:total] == sorted_num:
        ans = tmp_op.copy()
        ans_len = len(tmp_op)
        return ans, ans_len
    if total <= 3 and len(tmp_op) == 8:
        return ans, ans_len
    if total == 4 and len(tmp_op) == 10:
        return ans, ans_len
    for i in range(11):
        if is_unnecessary_op(A, B, i, tmp_op, head, tail):
            continue
        tmp_op.append(OPS[i])
        A, B, _ = do_op([], A, B, i)
        ans, ans_len = dfs_between_stack(A, B, head, tail, sorted_num, tmp_op, ans, ans_len)
        tmp_op.pop()
        A, B, _ = undo_op([], A, B, i)
    return ans, ans_len

def search_all_patterns(A, B, op, head, tail):
    total = tail - head + 1
    sorted_num = list(range(head, tail + 1))
    tmp_op = []
    ans = []
    ans_len = 2147483647
    ans, ans_len = dfs_between_stack(A, B, head, tail, sorted_num, tmp_op, ans, ans_len)
    # if not ans and not list(A)[:total] == sorted_num:
    #     debug(A, B)
    #     print("error!!", head, tail)
    #     exit(8)
    op.extend(ans)
    for p in ans:
        A, B, _ = do_op([], A, B, OPS.index(p))
    return A, B, op

# ----------------------------------
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
    if total <= LAST_BLOCK_SIZE:
        A, B, op = search_all_patterns(A, B, op, head, tail)
    else:
        for i in range(total):
            num = get_move_num(A, B, stack_place)
            m = len(nums_range_per_block)
            for i in range(m):
                mn, mx = nums_range_per_block[m - i - 1]
                if mn <= num <= mx:
                    A, B, op = move_num(A, B, op, stack_place, movable_stack_place[i])
                    break
    return A, B, op

def find_movable_stack_place(stack_place):
    movable_stack_place = []
    for i in range(1, 5):
        if i != stack_place:
            movable_stack_place.append(i)
    return movable_stack_place

def set_block_size(n, total):
    if n < 250:
        if total <= 8:
            each_block_size = total // 2
            block_count = 2
        else:
            each_block_size = total // 3
            block_count = 3
    else:
        each_block_size = total // 3
        block_count = 3
    return each_block_size, block_count

def set_block_num_range(stack, head, total, nums_range_per_block, each_block_size, block_count):
    new_tail = head - 1
    for i in range(block_count):
        new_head = new_tail + 1
        new_tail = new_head + each_block_size - 1
        if i < total % block_count:
            new_tail += 1
        if new_head > new_tail:
            continue
        stack.append((new_head, new_tail))
        nums_range_per_block.append((new_head, new_tail))
    return stack, nums_range_per_block

'''
        500        100
    (n >= 250)  (n < 250)
1-4 :  dfs
  5 :  2 2 1  ->  3 2
  6 :  2 2 2  ->  3 3
  7 :  3 2 2  ->  4 3
  8 :  3 3 2  ->  4 4
'''
def set_nums_range_per_block(n, stack, head, tail):
    total = tail - head + 1
    nums_range_per_block = []
    if total <= LAST_BLOCK_SIZE:
        return stack, nums_range_per_block
    each_block_size, block_count = set_block_size(n, total)
    stack, nums_range_per_block = set_block_num_range(stack, head, total, nums_range_per_block, each_block_size, block_count)
    return stack, nums_range_per_block

def divide_nums_to_other_stacks(n, stack, A, B, op, head, tail):
    stack_place = find_the_block_place(A, B, head, tail)
    movable_stack_place = find_movable_stack_place(stack_place)
    stack, nums_range_per_block = set_nums_range_per_block(n, stack, head, tail)
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
        stack, A, B, op = divide_nums_to_other_stacks(n, stack, A, B, op, head, tail)
    return A, op

# ----------------------------------
def erase_adjacent_op(op, erase_1, erase_2):
    new_op = []
    for s in op:
        if new_op and sorted([erase_1, erase_2]) == sorted([new_op[-1], s]):
            new_op.pop()
            continue
        new_op.append(s)
    return new_op

def erase_pair_op(r_count, erase_1, erase_2, new_op):
    while r_count[0] and r_count[1]:
        r_count[0] -= 1
        r_count[1] -= 1
    new_op.extend([erase_1] * r_count[0])
    new_op.extend([erase_2] * r_count[1])
    return r_count, new_op

def erase_unnecessary_op(op, erase_1, erase_2):
    new_op = []
    r_count = [0] * 2
    for s in op:
        if s in ("sa", "sb", "ss", "pa", "pb"):
            r_count, new_op = erase_pair_op(r_count, erase_1, erase_2, new_op)
            r_count = [0] * 2
            new_op.append(s)
            continue
        if s == erase_1:
            r_count[0] += 1
        elif s == erase_2:
            r_count[1] += 1
        else:
            new_op.append(s)
    r_count, new_op = erase_pair_op(r_count, erase_1, erase_2, new_op)
    return new_op

def replace_pair_op(r_count, new_op, before_1, before_2, after):
    while r_count[0] and r_count[1]:
        new_op.append(after)
        r_count[0] -= 1
        r_count[1] -= 1
    new_op.extend([before_1] * r_count[0])
    new_op.extend([before_2] * r_count[1])
    return r_count, new_op

def replace_op(op, before_1, before_2, after):
    new_op = []
    r_count = [0] * 2
    for s in op:
        if s in ("sa", "sb", "ss", "pa", "pb"):
            r_count, new_op = replace_pair_op(r_count, new_op, before_1, before_2, after)
            r_count = [0] * 2
            new_op.append(s)
            continue
        if s == before_1:
            r_count[0] += 1
        elif s == before_2:
            r_count[1] += 1
        else:
            new_op.append(s)
    r_count, new_op = replace_pair_op(r_count, new_op, before_1, before_2, after)
    return new_op

# ----------------------------------
# n >= 6
def solve_over_6(n, A, B):
    start_time = time.time()
    sorted_a = sorted(A)
    op = []
    A, op = stack_dfs(n, A, B, op)
    for _ in range(20):
        op = replace_op(op, "ra", "rb", "rr")
        op = replace_op(op, "ra", "rrr", "rrb")
        op = replace_op(op, "rb", "rrr", "rra")
        op = replace_op(op, "rr", "rra", "rb")
        op = replace_op(op, "rr", "rrb", "ra")
        op = replace_op(op, "rra", "rrb", "rrr")
        op = erase_unnecessary_op(op, "ra", "rra")
        op = erase_unnecessary_op(op, "rb", "rrb")
        op = erase_unnecessary_op(op, "rr", "rrr")
        op = erase_adjacent_op(op, "pa", "pb")
    if not op:
        print_color_str(RED, "[NO ANS..!!]")
    else:
        print(*op)
        print(len(op))
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
