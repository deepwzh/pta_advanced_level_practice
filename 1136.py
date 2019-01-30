a = input()
d = a
cnt = 0
while d[::-1] != d and cnt < 10:
    a = d
    b = d[::-1]
    d = str(int(a) + int(b))
    print("%s + %s = %s" % (a, b, d))
    cnt += 1
if cnt < 10:
    print("%s is a palindromic number." % d)
else:
    print("Not found in 10 iterations.")
