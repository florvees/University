# Ex 1

#print("There is "+str(len(set(str(input("Enter your numbers: ")).split())))+" unique number(s) in the set")

# Ex 2

# first_set = sorted(set(str(input("Enter your first set: ")).split()))
# second_set = sorted(set(str(input("Enter your second set: ")).split()))
# if (first_set[:len(second_set)] == second_set):
#     print("True")
# else:
#     print("False")

# Ex 3

# n = int(input("How many cities?"))
# cities = set()
# for i in range(n):
#     city = input("Please, enter the city: ").strip().lower()
#     if city in cities:
#         print("REPEAT")
#     else:
#         cities.add(city)
#         print("OK")

# Ex 4

# line = list(str(input("Enter your line: ")).split())
# for i in range(len(line)):
#     print(line[:i].count(line[i]), end=" ")
    
# Ex 5

# n = int(input())

# consumers_dict = {}
# for i in range(n):
#     line = input().split()
#     if line[0] not in consumers_dict:
#         consumers_dict[line[0]] = [[line[1],line[2]]]
#     else:
#         consumers_dict[line[0]].append([line[1],line[2]])

# IDs = list(consumers_dict.keys())
# for i in range(len(IDs)):
#     print("ID: "+IDs[i]+", покупки:")
#     for j in range(len(consumers_dict[IDs[i]])):
#         print(consumers_dict[IDs[i]][j][0], consumers_dict[IDs[i]][j][1])

# Ex 6

# symbols = ',.!?:;"()\t\n'
# text = str(input("Enter your text: "))
# for i in symbols:
#     text = text.replace(i, "")
# text = text.split()
# print("The asnwer is:\n" + "\n".join(sorted(sorted(set(text)), key=lambda word: text.count(word), reverse=True)))