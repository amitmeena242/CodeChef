from collections import defaultdict

def dfs(d,j,visited):
    global dcount
    
    visited[j-1]=True
    for i in d[j]:
        if visited[i-1]==False:
            dcount[cost[i-1]]+=1
            dfs(d,i,visited)

def prod(arr):
    mod = 1000000007
    res=1
    for i in arr:
        res*=i
        res%=mod
    return res

n=int(input())
cost=list(map(int,input().split()))
d=defaultdict(list)
for _ in range(int(input())):
    a,b=map(int,input().split())
    d[a].append(b)
    d[b].append(a)
arr=[]
visited=[False]*n


for i in d:
    global dcount
    dcount = defaultdict(int)
    for j in d[i]:
        if visited[j-1]==False:
            dcount[cost[j-1]]+=1
            dfs(d,j,visited)
    if len(dcount):
        minm = float("inf")
        for i in dcount:
            minm =min(i,minm)
        arr.append(dcount[minm])
print(prod(arr))
