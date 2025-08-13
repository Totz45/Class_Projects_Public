def main():
    n = int(input("what's N? "))
    for s in sheep(n):
        print(s)

def sheep(n):
    for i in range(n):
        yield "P" * i #return one at a time

#puttsx3 text to speech library (.init(), say(), runAndWait())

if __name__ == "__main__":
    main()