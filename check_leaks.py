filepath = "valgrind.log"

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


no_leaks_message = "All heap blocks were freed -- no leaks are possible"

with open(filepath) as f:
    contents = f.read()
    if no_leaks_message in contents:
        print_color_str(GREEN, "[LEAKS OK] ")
    else:
        print_color_str(RED, "[LEAKS NG] ")