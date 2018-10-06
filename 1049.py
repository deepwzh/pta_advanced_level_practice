# a = int(input())
cnt = 0
def f(n):
  str_n = str(n)
  str_l = len(str_n)
  if str_l == 0:
    return 0
  if str_l == 1:
    if n >= 1:
      return 1
    else:
      return 0
  res = 0
  if str_n[0] > '1':
    res += 10**(str_l -1) 
  elif str_n[0] == '1':
    res += (int(str_n[1:]) + 1)
  res += f(int(str_n[1:]))
  res += f(int(10**(str_l - 1) - 1)) * (int(str_n[0])) 
  return res

for i in range(100):
    print(i + 1, f(i + 1))
# for i in range(1,a + 1):
#   for c in str(i):
#     if c == '1':
#       cnt += 1
# print(cnt)
# 1
# 1x
# f(135) = 35 + 1 + f(35)
# f(2531) = 1000 + f(531)
# f(12) = 3 + f(2)*2 = 5