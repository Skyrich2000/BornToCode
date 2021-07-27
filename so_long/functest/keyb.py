l  = []
out = ['null' for _ in range(60)]

for i in range(52):
	a = input().split()
	out[int(a[1])] = a[0]

print(out)