def check(l):
    r = l[0]
    l.pop(0)
    for j in l:
        if j>r:
            return -1
    return 1

t = int(input())
for i in range(t):
    l = list(map(int,input().split()))
    res = check(l)
    if res == 1:
        print("Champions")
    else:
        print("-1")
