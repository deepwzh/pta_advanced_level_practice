a, b, c = map(lambda x: int(x),input().split(' '))
def solve(a, b):
  s = map(lambda x: int(x), input().split(' '))
  cnt = 0
  sta = []
  for num in s:
    while cnt < num:
      cnt += 1
      sta.append(cnt)
    if len(sta) == 0 or len(sta) > a:
      return False
    if sta[-1] == num:
      sta.pop()
    else:
      return False
  return True
for i in range(c):
  if solve(a, b):
    print("YES")
  else:
    print("NO")