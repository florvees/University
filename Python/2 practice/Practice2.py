#Practice 1, 1 ex.

first, second, third = int(input()), int(input()), int(input())
if (first==second==third):
    print(first, second, third)
elif (first==second!=third):
    print(first, second)
elif (first==third!=second):
    print(first, third)
elif (second==third!=first):
    print(second, third)
else:
    print("No equal numbers")

#Practice 1, 2.1 ex

# n = int(input())
# endl = ' '*((n+1)//10)
# for i in range(n+1):
#     for j in range(i):
#         print(j+1,end=endl)
#     print('\t')

#Practice 1, 2.2 ex
    
# n = int(input())
# free_space = '  '*(n//10)
# free_space_test = '  '*((n//10)+1)

# for i in range(n):
#     print(' '*(n-i-1),end=' ')
#     for j in range(i+1):
#         print(i-j+1,end=free_space)
#     for j in range(i):
#         print(j+2,end=free_space)
#     print(' '*(n-i-1),end='\n')
