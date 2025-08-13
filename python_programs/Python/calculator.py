def remainder(one, two): #function with parameters
    three = int(one) % int(two)
    print(three) # '**' power of a number
def main():
    x = input("first variable") #can also use float
    y = input("second variable") #can put int outside
    z = int(x) + int(y)
    #can round() to int from float
    print(z)
    print(f"{z:,}")

    z = round(int(x) / int(y), 3)
    print(z)

    remainder(y, x)
main() #call main function