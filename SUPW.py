import sys
input = sys.stdin.readline
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def getMin(arr,n):
    mn = float('inf')
    for i in range(n):
        mn = min(mn,arr[i])
    return mn

n = inp()
arr = inlt()
for i in range(n-4,-1,-1):
    arr[i] += min(arr[i+1],arr[i+2],arr[i+3])
print(getMin(arr,min(n,3)))
