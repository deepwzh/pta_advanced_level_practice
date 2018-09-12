"""
此代码不能过最后一组样例，Python运行的过慢，后来换C++写的
"""
n, k = map(lambda x: int(x), input().split(' '))
u = []
for i in range(n):
    num, name, grade = input().split(' ')
    grade = int(grade)
    u.append((num, name, grade))
results = (sorted(u, key= lambda x: (x[k - 1],x[0])))
for result in results:
    print(*result)