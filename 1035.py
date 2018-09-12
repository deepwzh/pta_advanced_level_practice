n = int(input())
data = []
res = []
for i in range(n):
    team, pwd = input().split(' ')
    new_pwd = []
    m = {
        '1':'@',
        '0':'%',
        'l': 'L',
        'O': 'o'
    }
    for c in pwd:
        if c in m.keys():
            new_pwd.append(m[c])
        else:
            new_pwd.append(c)
    new_pwd = ''.join(new_pwd)
    if new_pwd != pwd:
        # cnt += 1
        res.append((team, new_pwd))
if not res:
    if n == 1:
        print('There is 1 account and no account is modified')
    else:
        print('There are %d accounts and no account is modified' % n)
else:
    print(len(res))
    for a in res:
        print(*a)