n=int(input())
a=[int(i) for i in input().split()]

a.sort()

c=a[0]
d=0
for i in range(1,n):
    x=a[i]*i
    d+=(x-c)
    c+=a[i]  
print(d)
