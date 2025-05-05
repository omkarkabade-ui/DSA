# Experiment No: 2

print("Hello World! Welcome To Sets")

# Taking input for Set A
a = set()
no = int(input("Enter the total number in Set A: "))
for i in range(no):
    m = int(input("Enter elements: "))
    a.add(m)

# Taking input for Set B
b = set()
no = int(input("Enter the total number in Set B: "))
for i in range(no):
    m = int(input("Enter elements: "))
    b.add(m)

print("Set A:", a)
print("Set B:", b)

# Menu-driven program
while True:
    print("\n\n\n ***** MENU ***** \n")
    print("1 : Union")
    print("2 : Intersection")
    print("3 : Set Difference")
    print("4 : Subset")
    print("5 : Is Empty")
    print("6 : Length of A")
    print("7 : Length of B")
    print("8 : Searching")
    print("9 : Add Element")
    print("10: Remove Element")
    print("11: Exit")

    ch = int(input("\n***** Enter your Choice ****** \n"))

    if ch == 1:
        print("\n Union of A and B:", a.union(b))
    elif ch == 2:
        print("\n Intersection of A and B:", a.intersection(b))
    elif ch == 3:
        print("\n Set difference A-B:", a - b)
    elif ch == 4:
        if a.issubset(b):
            print("\nA is a subset of B")
        else:
            print("\nA is NOT a subset of B")
    elif ch == 5:
        if len(a) == 0:
            print("\nSet A is Empty")
        else:
            print("\nSet A is not empty")
    elif ch == 6:
        print("Length of A =", len(a))
    elif ch == 7:
        print("Length of B =", len(b))
    elif ch == 8:
        num = int(input("\n Enter element to be searched: "))
        if num in a:
            print("\nNumber is found in Set A")
        elif num in b:
            print("\nNumber is found in Set B")
        else:
            print("\nSorry! Number not found")
    elif ch == 9:
        ad = int(input("Enter number to be added in Set A: "))
        a.add(ad)
        print("\nNumber added in Set A")
        print("\nUpdated Set A:", a)
    elif ch == 10:
        rm = int(input("Enter number to delete: "))
        if rm in a:
            a.remove(rm)
            print("\nNumber removed")
        else:
            print("\nNumber not found in Set A")
        print("\nUpdated Set A:", a)
    elif ch == 11:
        print("\nExiting the program. Goodbye!")
        break
    else:
        print("\nInvalid choice! Please enter a valid option.")
