from calculator2 import square #import function from another program I coded
#pytest, import library--command on terminal
#use 'with' pytest.raises(TypeError)
#mkdir - make new folder -> __init__.py is a visual indicator for a package
def main():
    test_square()

def test_square():
    try:
        assert square(4) == 16 #if fail AssertionError
    except AssertionError:
        print("4 squared is not 4")
    try:
        assert square(-3) == 9 #if fail AssertionError
    except AssertionError:
        print("-3 squared is not 9")
    try:
        assert square(0) == 0 #if fail AssertionError
    except AssertionError:
        print("0 squared is not 0")


if __name__ == "__main__":
    main()