#constants at top, All caps
class Cat:
    MEOW = 3
    """    
    function name: meow()
    function purpose: meow three times
    parameters: None
    returns: None
    
    """
    def meow(self):
        for _ in range(Cat.MEOW):
            print("meow")

cat = Cat()
cat.meow()


#argparse can be imported
#print usage if program needs arguments
#mypy for checking type, use pip ": int" <-type hint