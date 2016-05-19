nn = input()
sum = 0
it = 2**2000
while (sum+1)*sum/2 != nn:
    if (sum+it+1)*(sum+it)/2 <= nn:
        sum += it
    it /= 2
print sum
