from sys import stdin

n, q = [int(x) for x in stdin.readline().split()]
nums = [int(x) for x in stdin.readline().split()]
ones = sum(nums)

for _ in range(q):
    t, x = [int(x) for x in stdin.readline().split()]
    if t == 1:
        x -= 1
        if nums[x] == 1:
            ones -= 1
        else:
            ones += 1
        nums[x] = 1 - nums[x]
    else:
        if x <= ones:
            print("1")
        else:
            print("0")
