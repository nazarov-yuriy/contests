x = int(input())
if x==1:
    print(1)
elif x%3==1:
    x=int((x-4)/3)
    print(4*3**x)
elif x%3==2:
    x=int((x-2)/3)
    print(2*3**x)
else:
    x=int(x/3)
    print(3**x)
