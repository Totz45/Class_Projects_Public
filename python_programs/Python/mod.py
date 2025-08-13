import sys
from random import choice #called modules format is similar to objects in c++
from random import randint# shuffle, 
#statistics library
#pip used to install packages
#cowsay and requests can be installed with pip
#JSON textbased formatted
#can import from other py files but do not use main for those calling programs.
# if __name__ == __main__
#   main() -- use in calling programs
while True:
    try:
        print("Oi what coordinates did you pick,", sys.argv[1])
        coin = choice(["A", "B", "C", "D", "E", "F"])
        number = randint(1, 6)
        print(coin, number)
        break
    except IndexError: 
        print("what?! U speaking Engrish")
        break