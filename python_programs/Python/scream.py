def main():
    scream("Yeowch", "Help", "Stop")

def scream(*phrase):
    uppercase = [word.upper() for word in phrase]        #map(str.upper, phrase) 
    print(*uppercase)

if __name__ == "__main__":
    main()