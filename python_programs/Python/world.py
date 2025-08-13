def main():
    x = get_int("what is x? ")
    print(f"x is {x}")
def get_int(prompt):    
    while True:
        try:
            return int(input(prompt))
        except ValueError: #try to run as intend, except is to catch errors.
            print("x is not an integer")
            pass #pass is an ignore statement.
            #can use else here for other errors.
main()