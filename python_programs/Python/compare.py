x = int(input("Number 1: "))
y = int(input("Number 2: "))

if x < y:
    print("x is less than y")
elif x > y: #else if is elif in python
    print("x is greater than y")
else:
    print("X is equal to y")
if x<y or x>y: #use or, and instead of ||, &&
    print("x is not equal to y")
