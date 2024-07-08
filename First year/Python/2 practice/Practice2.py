# Ex 1

# n = int(input())
#
# prev_str = [1]
# for i in range(n):
#     print(" "*(n-i), end='')
#     print(*prev_str)
#     current_str = prev_str.copy()
#     current_str.append(1)
#     for j in range(1, len(current_str) - 1):
#         current_str[j] = prev_str[j - 1] + prev_str[j]
#     prev_str = current_str

# Ex 2

n = int(input())

prev_str = [1]
for i in range(n):
    print(" " * (n - i), end='')
    for elem in prev_str:
        if (elem % 2) == 1:
            print(' *  ', end='')
        else:
            print('    ', end='')
    print()
    print(" " * (n - i), end='')
    for elem in prev_str:
        if (elem % 2) == 1:
            print('* * ', end='')
        else:
            print('    ', end='')
    print()
    current_str = prev_str.copy()
    current_str.append(1)
    for j in range(1, len(current_str) - 1):
        current_str[j] = prev_str[j - 1] + prev_str[j]
    prev_str = current_str