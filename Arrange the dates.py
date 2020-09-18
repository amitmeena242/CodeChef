def valid(m,d,y):
    daz = [31,29,31,30,31,30,31,31,30,31,30,31]
    if m < 1 or m > 12:
        return False
    if y < 1:
        return False
    if d < 1 or d > daz[m-1]:
        return False
    if m == 2 and d == 29:
        if y%4 > 0:
            return False
        if y%100 == 0 and y%400 != 0:
            return False
    return True

n = int(input())
dats = []
for i in range(n):
    d,m,y = list(map(int,input().split("/")))
    dats.append(y * 10000 + m * 100 + d)
    
s = sorted(dats)
for i in s:
    y = i//10000
    ui = i - 10000*y
    m = ui//100
    d = ui%100
    print(str(d)+"/"+str(m)+"/"+str(y))
