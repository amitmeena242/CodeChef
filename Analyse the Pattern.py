# cook your dish here
for t in range(int(input())):
    list=['S','S','E','C']
    numbers=[1,2,3,4,3,2,1]
    n=int(input())
    curr=numbers[n%7-1]
    for i in range(curr):
        print(ord(list[i]),end=" ")
    print("\n", end="")
