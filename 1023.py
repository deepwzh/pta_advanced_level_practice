a = input()
res = int(a) * 2
if sorted(str(a)) == sorted(str(res)):
  print("Yes")
else:
  print("No")
print(res)