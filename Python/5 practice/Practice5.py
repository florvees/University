# Ex 1

# prod = 1
# with open("input1.txt", "r", encoding = "utf-8") as file_in:
#     data = file_in.readline().split()
#     for elem in data:
#         prod *= int(elem)
# with open("output1.txt", "w", encodin = "utf-8") as file_out:
#     file_out.write(prod)

# Ex 2

data = []
with open("input2.txt", "r", encoding = "utf-8") as file_in:
    data = file_in.read().splitlines()
    data.sort()
with open("output2.txt", "w", encoding = "utf-8") as file_out:
    file_out.write('\n'.join(data))