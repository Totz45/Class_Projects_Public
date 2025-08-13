students = [
    {"name": "Tate", "Major": "CmpE"},
    {"name": "Sean", "Major": "EE"},
    {"name": "Max", "Major": "ME"},
    {"name": "Bane", "Major": "CmpE"},
]

def is_Cmpe(s):
    return s["Major"] == "CmpE"

houses = filter(is_Cmpe, students)

for house in sorted(houses, key=lambda s: s["name"]):
    print(house["name"])


"""
houses = [
    student["name"] for student in students if student["Major"] == "CmpE" #list comprehension
]
    for dict comprehension {"name": student, "Major": CmpE} for student in students

    for i, student in enumerate(students):
        print(i + 1, student)

    

for house in sorted(houses):
    print(house)
"""