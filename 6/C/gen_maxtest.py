n = 50
a = 31
b = 53
c = []

for i in range(n):
    d = []

    for j in range(n):
        r = (i + j * j) * i * j * a + b * abs(i - j) + 73
        r %= 100
        d.append(r)

    c.append(d)

print(n)

for i in range(n):
    for j in range(n):
        print(c[i][j], end = ' ')

    print()
