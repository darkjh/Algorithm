fibonacci = 1
old1 = 0
old2 = 1
limit = 1000

i = 1

while len(str(fibonacci)) < limit:
    fibonacci = old1 + old2
    old1 = old2
    old2 = fibonacci
    i = i + 1

print(i)
