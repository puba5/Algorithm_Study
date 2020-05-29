n = int(input())

m = 1000000

fibo = {}

fibo[0] = 0
fibo[1] = 1

for i in range(2, m * m):
	fibo[i] = (fibo[i - 1] + fibo[i - 2]) % m
	if fibo[i - 1] == 0 and fibo[i] == 1:
		p = i - 1
		break

print(fibo[n % p])