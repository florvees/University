import numpy as np

# Ex 1

# with open("input1.txt", "r") as file:
#     # pure_data = file.read().split()
#     # data = []
#     # for elem in pure_data:
#     #     data.append(elem.split(","))
#     # for i in range(len(data)):
#     #     for j in range(len(data[i])):
#     #         data[i][j] = int(data[i][j])
#     # matrix = np.matrix(data)
#     # print(matrix)
#
#     matrix = np.array([list(map(int, i.split(","))) for i in file.read().split()])
#     print("Sum of all elements: " + str(matrix.sum()))
#     print("Max value: " + str(matrix.max()))
#     print("Min value: " + str(matrix.min()))

# Ex 2

# print("Input the X vector: ")
# x = np.array(list(map(int, input().split())))
# result = np.unique(x, return_counts=True)
# print(result[0])
# print(result[1])

# Ex 3

# arr = np.random.normal(size=(10, 4))
# print(arr)
# print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
# print("Min value:                " + str(arr.min()))
# print("Max value:                " + str(arr.max()))
# print("Mean value:               " + str(arr.mean()))
# print("Standard deviation value: " + str(arr.std()))
# print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
# variable = arr[:5, :]

# Ex 4

# print("Input the X vector: ")
# x = np.array(list(map(int, input().split())))
# max_value = x.min()
# for first in range(x.size-1):
#     second = first+1
#     if x[first] == 0:
#         if x[second] > max_value:
#             max_value = x[second]
# print(max_value)

# Ex 5



# Ex 6

# a = np.arange(16).reshape(4, 4)
# print("~~~~~~~~~~~~~~~")
# print(a)
# print("~~~~~~~~~~~~~~~")
# tmp = a[0, :].copy()
# a[0, :] = a[2, :]
# a[2, :] = tmp
# print(a)
# print("~~~~~~~~~~~~~~~")

# Ex 7

# url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
# iris = np.genfromtxt(url, delimiter=',', dtype='object')
#
# vector = iris[:, 4]
# result = np.unique(vector, return_counts=True)
#
# print("Unique values:", result[0])
# print("Amount of unique values:", result[1])

# Ex 8

# arr = np.array([0, 1, 2, 0, 0, 4, 0, 6, 9])
# print("Non-zero indexes:", np.flatnonzero(arr))

