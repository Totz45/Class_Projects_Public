import re

email = input("What is your email? ").strip()
#\w is word -> [a-zA-Z0-9_]
#\d decimal
#\D not a decimal
#\s whitespace
#\S no whitespace
#\W not a word
if re.search(r"^\w+@(\w+\.)?\w+\.edu$", email, re.IGNORECASE):
# .-any character except newline
# *-0 or more repetitions
# +-1 or more repetitions
# ?-0 or 1 repetitions
# {m}-m repetions
# {m, n}- m-n repetitions
# ^ match start of string
# $ match end of the string
    # [] set of characters, no commas 
    # [^] complement the set
    # | or
    # () grouping
# f-format r-raw->use for regular expression
    print("Valid")
else:
    print("Invalid")