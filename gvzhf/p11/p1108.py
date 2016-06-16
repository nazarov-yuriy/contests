n = input()
d = 1
m = 1
for x in range(0, n):
    m *= d
    d = m+1
    print d
