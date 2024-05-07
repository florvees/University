# Ex 1

prod = 1
with open("1st/input1.txt", "r", encoding="utf-8") as file_in:
    data = file_in.readline().split()
    for elem in data:
        prod *= int(elem)
with open("1st/output1.txt", "w", encoding="utf-8") as file_out:
    file_out.write(str(prod))

# Ex 2

# data = []
# with open("2nd/input2.txt", "r", encoding="utf-8") as file_in:
#     data = file_in.read().splitlines()
#     data.sort()
# with open("2nd/output2.txt", "w", encoding="utf-8") as file_out:
#     file_out.write('\n'.join(data))

# Ex 3


