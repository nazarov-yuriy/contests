from sys import stdin

stdin.readline()
s = sum([int(x) for x in stdin.readline().split()])
print(s * s)
