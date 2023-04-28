import statistics
import subprocess
import sys

filepath = "out2"

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
# run
def run_cmd(cmd):
    subprocess.run(cmd, shell=True)

heighest = 0
median = []
lowest = float("inf")

argc = int(sys.argv[1])

def run_and_calc_score():
    global heighest, median, lowest
    cmd = "python3 main.py $(python3 -c 'import random; print(*random.sample(range(1, " + str(argc + 1) + "), " + str(argc) + "))') > " + filepath
    print(cmd)
    run_cmd(cmd)

    with open(filepath) as f:
        args = f.readline()
        op = f.readline()
        op_len = f.readline()

        x = int(op_len)
        heighest = max(heighest, x)
        median.append(x)
        lowest = min(lowest, x)

        cmd = "python3 checker.py" + "<" + filepath
        run_cmd(cmd)

for _ in range(int(sys.argv[2])):
    run_and_calc_score()
print("max   :", heighest)
print("median:", int(statistics.median(median)))
print("min   :", lowest)

# ----------------------------------------------------------
# python3 test_main.py [argc] [times]
# python3 test_main.py 100 500
# python3 test_main.py 500 500