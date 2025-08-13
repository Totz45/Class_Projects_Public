import re
# := assign and ask boolean question
# (?:...) - non capture grouping
name = input("What is your name? ").strip()
if matches := re.search(r"^(.+), ?(.+)$", name):
    name = matches.group(2) + " " + matches.group(1)
print(f"hello, {name}")