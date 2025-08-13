#names = []
name = input("what is your name? ")
#using with no need to include file.close()
with open("names.txt", "a") as file:#first argument is file, second argument is permissions w-write a-append r-read
    #for _ in range(3):
        #name = input("what's your name? ")
        #names.append(name)
    #for name in sorted(names):
        file.write(f"{name}\n")
#file.close()
#file.readlines()