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

# # Multivariate normal distribution
#
# import time
# import scipy
# from scipy.stats import multivariate_normal
#
# # N = int(input("Enter the value: "))
# # D = N
# #
# # X = np.random.normal(size=(N, D))
# # M = np.random.normal(size=D)
# # C = np.cov(X)
#
# X = np.array([[5, 5], [1, 2]])
# M = np.array([1, 5])
# C = np.array([[5, 2], [2, 2]])
#
# start_mine = time.perf_counter()
# value_mine = -0.5 * (np.log(2 * np.pi) + np.log(np.linalg.det(C))
#                      + np.einsum('ij,ij->i', X - M, np.dot(np.linalg.inv(C), X - M)))
# finish_mine = time.perf_counter()
#
# duration_mine = finish_mine - start_mine
#
# start_scipy = time.perf_counter()
# value_scipy = scipy.stats.multivariate_normal(M, C).logpdf(X)
# finish_scipy = time.perf_counter()
#
# duration_scipy = finish_scipy - start_scipy
#
# print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
# print(f"My value is: {value_mine}")
# print(f"Scipy value is: {value_scipy}")
# print(f"The difference between them: {abs(value_mine-value_scipy)}")
# print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
# print(f"My value performed in: {duration_mine}")
# print(f"Scipy value performed in: {duration_scipy}")
# print(f"The difference between them: {abs(duration_mine-duration_scipy)}")
# print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")

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
