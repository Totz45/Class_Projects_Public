def main():
    x = int(input("What is x? ")) #can also use float
    print("x squared is ", square(x))

def square(one): #function with parameters
    return one * one
if __name__ == "__main__":
    main() #call main function