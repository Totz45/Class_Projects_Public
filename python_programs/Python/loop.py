def main():
    x = int(input("How many times do you want to iterate"))
    i = x
    match x: #switch statement
        case 2:
            while i != 0: #while loop
                i -= 1
                print(i)
        case 3:
            for _ in range(3): #range is like an iterating for loop
                i -= 1
                print(i)
        case _:
            print("Update number\n" * x, end="")#simple iteration for variable number of times.
    soup = ["Tomato", "chesse", "lettuce"]
    for ingredient in soup:
        print(len(soup), ingredient)
    pizza = {"Cheese": "Cheese Pizza", "Pepperoni": "Pepperoni Pizza"}#dictionary
    for typeOf in pizza:
        print(typeOf, pizza[typeOf])#None prints none

main()