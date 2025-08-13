def f(*args, **kwargs):
    print("Named:", kwargs)

f(galleon=50, knuts=5, herds=35)


# use * to unpack a list, and use ** to unpack a dictionary
# can use *args for positional arguments, can use **kwargs to call with keys