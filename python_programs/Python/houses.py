students = [
    {"name": "Tate", "Major": "CmpE"},
    {"name": "Sean", "Major": "EE"},
    {"name": "Max", "Major": "ME"},
    {"name": "Bane", "Major": "CmpE"},
]

houses = set()
for student in students:
    if student["Major"] not in houses:
        houses.add(student["Major"])

for house in sorted(houses):
    print(house)