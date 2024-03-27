# Ex 1

# line = input("Enter your string: ")
# new_line = ""
# i = 0
# while i < len(line):
# 	if i == len(line) - 1:
# 		new_line += line[i]
# 		break
# 	counter = 1
# 	while (line[i] == line[i+counter]):
# 		counter += 1
# 		if (i+counter >= len(line)):
# 			break
# 	new_line += line[i]
# 	if counter > 1:
# 		new_line += str(counter)
# 		i += counter-1
# 	i += 1
# print("Here's the shorted version: ",new_line)

# Ex 2

# line = str(input("Enter your shorted line: "))
# new_line = ""
# i = 0
# while i < len(line):
# 	if i < len(line) - 1:
# 		if line[i + 1].isdigit():
# 			new_line += line[i] * int(line[i + 1])
# 			i+= 1
# 		else:
# 			new_line += line[i]
# 	else:
# 		new_line += line[i]
# 	i += 1
# print("Here's the line: " + new_line)

#Ex 3

# line = list(str(input("Enter the line: ")))
# new_line = ""
# if (len(line) == 3):
#     match int(line[0]):
#         case 1: new_line += "сто "
#         case 2: new_line += "двести "
#         case 3: new_line += "триста "
#         case 4: new_line += "четыреста "
#         case 5: new_line += "пятьсот "
#         case 6: new_line += "шестьсот "
#         case 7: new_line += "семьсот "
#         case 8: new_line += "восемьсот "
#         case 9: new_line += "девятьсот "
#     line = line[1:]
# if (len(line) == 2):
#     match int(line[0]):
#         case 1: 
#             match int(line[1]):
#                 case 1: new_line += "одиннадцать "
#                 case 2: new_line += "двенадцать "
#                 case 3: new_line += "тринадцать "
#                 case 4: new_line += "четырнадцать "
#                 case 5: new_line += "пятнадцать "
#                 case 6: new_line += "шестнадцать "
#                 case 7: new_line += "семьнадцать "
#                 case 8: new_line += "восемнадцать "
#                 case 9: new_line += "девятнадцать "
#             line = line[1:]
#         case 2: new_line += "двадцать "
#         case 3: new_line += "тридцать "
#         case 4: new_line += "сорок "
#         case 5: new_line += "пятьдесят "
#         case 6: new_line += "шестьдесят "
#         case 7: new_line += "семьдесят "
#         case 8: new_line += "восемьдесят "
#         case 9: new_line += "девяносто "
#     line = line[1:]
# if (len(line) == 1):
#     match int(line[0]):
#         case 1: new_line += "один "
#         case 2: new_line += "два "
#         case 3: new_line += "три "
#         case 4: new_line += "четыре "
#         case 5: new_line += "пять "
#         case 6: new_line += "шесть "
#         case 7: new_line += "семь "
#         case 8: new_line += "восемь "
#         case 9: new_line += "девять "
# print(new_line)

# Ex 4

# dictionary = {}
# line = list(str(input("Enter the line: ")).split())
# for elem in line:
#     if elem in dictionary:
#         dictionary[elem] += 1
#     else:
#         dictionary[elem] = 1
# for elem in dictionary.values():
# 	print(elem, end=" ")

# Ex 5

# matrix = [
#     [10, 20, 30],
#     [40, 50, 60],
#     [70, 80, 90]
# ]
# det = (matrix[0][0]*matrix[1][1]*matrix[2][2] + matrix[2][0]*matrix[0][1]*matrix[1][2] + matrix[0][2]*matrix[1][0]*matrix[2][1]) - (matrix[0][2]*matrix[1][1]*matrix[2][0] + matrix[0][0]*matrix[1][2]*matrix[2][1] + matrix[0][1]*matrix[1][0]*matrix[2][2])
# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         print(str(matrix[i][j]), end=" ")
#     print()
# if(det==0):
#     print("Линейно зависимы")
# else:
#     print("Линейно независисы")
     
# Ex 6

# print("Введите строку: ")
# line = str(input())
# arr = line.split(" ")
# print("Аббревиатура: ")
# for i in range(len(arr)):
#     print(arr[i][0].upper(), end="")
