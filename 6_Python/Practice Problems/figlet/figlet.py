from pyfiglet import Figlet
import random
import sys

figlet = Figlet()

def print_figlet(f, str):
    figlet.setFont(font = f)
    print(figlet.renderText(str))


if len(sys.argv) == 1:
    str = input("Input: ")
    f = random.choice(figlet.getFonts())
    print_figlet(f, str)

elif len(sys.argv) == 3 and (sys.argv[1] == '-f' or sys.argv[1] == '--font') and sys.argv[2] in figlet.getFonts():
    str = input("Input: ")
    f = sys.argv[2]
    print_figlet(f, str)

else:
    sys.exit("Invalid usage")
