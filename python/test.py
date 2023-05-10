import subprocess

LEAKS = True
filepath = "valgrind.log"
no_leaks_message = "All heap blocks were freed -- no leaks are possible"
ERROR = "Error\n"
num = 1

# ----------------------------------------------------------
# color
WHITE = "white"
RED = "red"
GREEN = "green"
YELLOW = "yellow"
BLUE = "blue"
color_dict = {"white" : "\033[37m",
              "red" : "\033[31m",
              "green" : "\033[32m",
              "yellow" : "\033[33m",
              "blue" : "\033[34m",
              "end" : "\033[0m"}

def print_color_str(color=WHITE, text=""):
    print(color_dict[color] + text + color_dict["end"])

def print_color_str_no_lf(color=WHITE, text=""):
    print(color_dict[color] + text + color_dict["end"], end="")

# ----------------------------------------------------------
# leaks
def check_leaks():
    global num
    with open(filepath) as f:
        contents = f.read()
        if no_leaks_message in contents:
            print_color_str_no_lf(GREEN, str(num) + ".[LEAKS OK] ")
        else:
            print_color_str_no_lf(RED, str(num) + ".[LEAKS NG] ")
    num += 1

# ----------------------------------------------------------
# run
def run_cmd(cmd):
    subprocess.run(cmd, shell=True)

def run_cmd_leaks(cmd):
    if LEAKS:
        cmd = 'valgrind --log-file=valgrind.log ./push_swap ' + cmd
    else:
        cmd = './push_swap ' + cmd
    # print(cmd)
    # print("============================")
    run_cmd(cmd)
    check_leaks()
    # print("============================\n")

def run_and_cmp(arg, expect):
    filepath = "out"
    cmd = './push_swap ' + arg + ' 2> ' + filepath
    # print(cmd)
    # print("============================")
    run_cmd(cmd)

    with open(filepath) as f:
        contents = f.read()
        if expect == contents:
            print_color_str(GREEN, "[OUTPUT OK] ")
        else:
            print_color_str(RED, "[OUTPUT NG] ")

# ----------------------------------------------------------
cmd = "touch " + filepath
run_cmd(cmd)

cmd = "make"
run_cmd(cmd)
print("================================")

# ----------------------------------------------------------
# error
run_cmd_leaks("")
run_and_cmp("", ERROR)

run_cmd_leaks("a")
run_and_cmp("a", ERROR)

run_cmd_leaks("a 5")
run_and_cmp("a 5", ERROR)

run_cmd_leaks("4a")
run_and_cmp("4a", ERROR)

run_cmd_leaks("-")
run_and_cmp("-", ERROR)

run_cmd_leaks("+")
run_and_cmp("+", ERROR)

run_cmd_leaks("+ 5")
run_and_cmp("+ 5", ERROR)

run_cmd_leaks("2147483648")
run_and_cmp("2147483648", ERROR)

run_cmd_leaks("-2147483649")
run_and_cmp("-2147483649", ERROR)

run_cmd_leaks("-2147483649 5")
run_and_cmp("-2147483649 5", ERROR)

run_cmd_leaks("0 0")
run_and_cmp("0 0", ERROR)

run_cmd_leaks("-0 0")
run_and_cmp("-0 0", ERROR)

run_cmd_leaks("-0 +0")
run_and_cmp("-0 +0", ERROR)

run_cmd_leaks("0 +0")
run_and_cmp("0 +0", ERROR)

run_cmd_leaks("02 2")
run_and_cmp("02 2", ERROR)

run_cmd_leaks("2 2")
run_and_cmp("2 2", ERROR)

run_cmd_leaks("2 2 5")
run_and_cmp("2 2 5", ERROR)

run_cmd_leaks("2 2 5 2")
run_and_cmp("2 2 5 2", ERROR)

# ----------------------------------------------------------
# nothing happend
run_cmd_leaks("02")
run_cmd_leaks("4")
run_cmd_leaks("-5 8")
run_cmd_leaks("-2147483648 0 2147483647")
run_cmd_leaks('""')
run_cmd_leaks('"" ""')
run_cmd_leaks('" "')
run_cmd_leaks('"" "  "')
run_cmd_leaks('"" "  " 5')
run_cmd_leaks('"    7"')
run_cmd_leaks('"7      "')
run_cmd_leaks('"  7      "')

# ----------------------------------------------------------
# ok
run_cmd_leaks("6 5")
run_cmd_leaks('"   7   3"')
run_cmd_leaks('5 "  7   3 "')
run_cmd_leaks('"" "  " " 7 " "  -6  2 "  2147483647')

# ----------------------------------------------------------