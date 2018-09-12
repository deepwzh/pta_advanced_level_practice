"""
此代码不能通过任何样例，占用内存空间过大
"""
n1, *u1 = input().split(' ')
n2, *u2 = input().split(' ')
u1 = list(map(lambda x: int(x), u1))
u2 = list(map(lambda x: int(x), u2))
u = sorted(u1 + u2)
length = len(u)
# print(u)
if length % 2 == 1:
    print(u[length//2])
else:
    print((u[length//2] + u[length//2 - 1]) / 2)
