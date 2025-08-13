alphabet = []

#module of csv
with open("names.csv") as file:
    for line in file:
        name, game = line.rstrip().split(",")
        #alphabet.append(f"{name} is in game: {game}")# can use name[0] and name[1] to seperate as well
        
        letter = {} #can initalize here
        letter["name"] = name
        letter["game"] = game
        alphabet.append(letter)
#def get_name(letter):
    #return letter["name"]

#can replace key with function, lambda is an anonymous function 
for letter in sorted(alphabet, key=lambda letter: letter["name"], reverse=True):
    print(f"{letter['name']} is in {letter['game']}")

#for letter in sorted(alphabet):
    #print(letter)