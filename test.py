import subprocess

LEAKS = True
filepath = "valgrind.log"
no_leaks_message = "All heap blocks were freed -- no leaks are possible"

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

# ----------------------------------------------------------
# leaks
def check_leaks():
    def print_color_str(color=WHITE, text=""):
        print(color_dict[color] + text + color_dict["end"])

    with open(filepath) as f:
        contents = f.read()
        if no_leaks_message in contents:
            print_color_str(GREEN, "[LEAKS OK] ")
        else:
            print_color_str(RED, "[LEAKS NG] ")

# ----------------------------------------------------------
# run
def run_cmd(cmd):
    if LEAKS:
        cmd = 'valgrind --log-file="valgrind.log" ./push_swap ' + cmd
    else:
        cmd = './push_swap ' + cmd
    print(cmd)
    print("============================")
    subprocess.run(cmd, shell=True)
    check_leaks()
    print("============================\n")


# ----------------------------------------------------------
cmd = "touch " + filepath
subprocess.run(cmd, shell=True)

run_cmd("make")
print("================================")

# ----------------------------------------------------------
# error
run_cmd("")
run_cmd("a")
run_cmd("a 5")
run_cmd("4a")
run_cmd("-")
run_cmd("+")
run_cmd("+ 5")
run_cmd("2147483648")
run_cmd("-2147483649")
run_cmd("-2147483649 5")
run_cmd("0 0")
run_cmd("-0 0")
run_cmd("-0 +0")
run_cmd("0 +0")
run_cmd("02 2")
run_cmd("2 2")
run_cmd("2 2 5")
run_cmd("2 2 5 2")

# ----------------------------------------------------------
# nothing happend
run_cmd("02")
run_cmd("4")
run_cmd("-5 8")
run_cmd("-2147483648 0 2147483647")
run_cmd('""')
run_cmd('"" ""')
run_cmd('" "')
run_cmd('"" "  "')
run_cmd('"" "  " 5')
run_cmd('"    7"')
run_cmd('"7      "')
run_cmd('"  7      "')

# ----------------------------------------------------------
# ok
run_cmd("6 5")
run_cmd('"   7   3"')
run_cmd('5 "  7   3 "')
run_cmd('"" "  " " 7 " "  -6  2 "  2147483647')

# ----------------------------------------------------------