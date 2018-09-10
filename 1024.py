a, b = map(lambda x: int(x), input().split(' '))
t = str(a)
res = None
is_find = False
if t == t[::-1]:
  res = (t, 0)
if not res:
  for i in range(b):
    u = int(t) + int(t[::-1])
    t = str(u)
    if t == t[::-1]:
      res = (t, i +1 )
      break
if not res:
  print(t)
  print(b)
else:
  print(res[0])
  print(res[1])