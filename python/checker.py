import sys
from collections import deque


# ----------------------------------------------------------
# color
WHITE = "white"
RED = "red"
GREEN = "green"
color_dict = {"white" : "\033[37m",
              "red" : "\033[31m",
              "green" : "\033[32m",
              "end" : "\033[0m"}

def print_color_str(color=WHITE, text=""):
    print(color_dict[color] + text + color_dict["end"])

def print_color_str_no_lf(color=WHITE, text=""):
    print(color_dict[color] + text + color_dict["end"], end="")

# ----------------------------------------------------------
def fin(msg):
    print("Error!! :", msg)
    exit()

# ----------------------------------
def debug_a():
    print("stack A", A)

def debug_b():
    print("stack B", B)

# ----------------------------------
def sa():
    if len(A) >= 2:
        A[0], A[1] = A[1], A[0]

def sb():
    if len(B) >= 2:
        B[0], B[1] = B[1], B[0]

def ss():
    sa()
    sb()

def pa():
    if B:
        A.appendleft(B.popleft())

def pb():
    if A:
        B.appendleft(A.popleft())

def ra():
    if len(A) >= 2:
        A.append(A.popleft())

def rb():
    if len(B) >= 2:
        B.append(B.popleft())

def rr():
    ra()
    rb()

def rra():
    if len(A) >= 2:
        A.appendleft(A.pop())

def rrb():
    if len(B) >= 2:
        B.appendleft(B.pop())

def rrr():
    rra()
    rrb()

# ----------------------------------
argv = sys.argv
# if (len(argv) == 1):
#     fin("no arguments")

# ----------------------------------
# A = deque(map(int, input().split()))
A = deque([])
for a in argv[1:]:
    if not a.isdigit():
        fin("invalid digit")
    x = int(a)
    if not (-2147483648 <= x <= 2147483647):
        fin("overflow")
    if x in A:
        fin("same number")
    A.append(x)
debug_a()

# ----------------------------------
valid_op = ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
# ops = list(input().split())
ops = []
is_op_correct = True
while True:
    try:
        x = input()
        if is_op_correct:
            if x in valid_op:
                ops.append(x)
            else:
                is_op_correct = False
    except EOFError:
        print("EOF")
        break
print("operations", ops)

# if not is_op_correct:
#     fin("invalid operation")
# if not ops:
#     fin("no operation")

# ----------------------------------
B = deque([])
for op in ops:
    if op == "sa":
        sa()
    elif op == "sb":
        sb()
    elif op == "ss":
        ss()
    elif op == "pa":
        pa()
    elif op == "pb":
        pb()
    elif op == "ra":
        ra()
    elif op == "rb":
        rb()
    elif op == "rr":
        rr()
    elif op == "rra":
        rra()
    elif op == "rrb":
        rrb()
    elif op == "rrr":
        rrr()
    # debug_a()
    # debug_b()
    # print()

if (sorted(A) == list(A)) and (not B):
    print_color_str(GREEN, "OK!")
else:
    print_color_str(RED, "KO!")
    exit(5)

# ----------------------------------

# OK
# python checker.py 100 2 6 292929 < op1.txt
# python checker.py 2 1 3 6 5 8 < op2.txt
# python checker.py 3 2 1 0 < op3.txt

# KO
# python checker.py 3 2 1 0 < op4.txt

# Error
# python checker.py 0 one 2 3
# python checker.py "" 1
