def insertion_sort(arr: list) -> list:
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1
    return arr

arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
print(insertion_sort(arr))