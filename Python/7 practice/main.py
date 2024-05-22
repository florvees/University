import numpy as np

with open("input1.txt", "r") as file:
    # pure_data = file.read().split()
    # data = []
    # for elem in pure_data:
    #     data.append(elem.split(","))
    # for i in range(len(data)):
    #     for j in range(len(data[i])):
    #         data[i][j] = int(data[i][j])
    # matrix = np.matrix(data)
    # print(matrix)
    matrix = np.array([list(map(int, i.split(","))) for i in file.read().split()])
    print("Sum of all elements: " + str(matrix.sum()))
    print("Max value: " + str(matrix.max()))
    print("Min value: " + str(matrix.min()))