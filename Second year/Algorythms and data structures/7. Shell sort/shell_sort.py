def shell_sort(arr: list) -> list:
    step = len(arr) // 2
    while step > 0:
        for i in range(step, len(arr)):
            j = i
            dif = j - step
            while dif >= 0 and arr[dif] > arr[j]:
                arr[dif], arr[j] = arr[j], arr[dif]
                j = dif
                dif = j - step
        step //= 2
    return arr

arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
print(shell_sort(arr))