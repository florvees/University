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

line = list(int(input("Enter your number: ")))
print(line)

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
