# Ex 1

# prod = 1
# with open("1st/input1.txt", "r", encoding="utf-8") as file_in:
#     data = file_in.readline().split()
#     for elem in data:
#         prod *= int(elem)
# with open("1st/output1.txt", "w", encoding="utf-8") as file_out:
#     file_out.write(str(prod))

# Ex 2

# with open("2nd/input2.txt", "r", encoding="utf-8") as file_in:
#     data = file_in.read().splitlines()
#     data.sort()
# with open("2nd/output2.txt", "w", encoding="utf-8") as file_out:
#     file_out.write('\n'.join(data))

# Ex 3

# data = []
# with open("3rd/input3.txt", "r", encoding="utf-8") as file_in:
#     for line in file_in.read().splitlines():
#         data.append(line.split())
#     data.sort(key=lambda x: int(x[2]))
# with open("3rd/output3_younger.txt", "w", encoding="utf-8") as file_younger:
#     file_younger.write(data[0][0]+" "+data[0][1]+" "+str(data[0][2]))
# with open("3rd/output3_older.txt", "w", encoding="utf-8") as file_older:
#     file_older.write(data[-1][0]+" "+data[-1][1]+" "+str(data[-1][2]))

# Ex 4