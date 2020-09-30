n=int(input())
s=input()
v,h=0,0
for i in range(n):
    if(s[i]=='V'):
        v+=1
    else:
        h+=1
if(v>h):
    print("Virat")
elif(v<h):
    print("Harshit")
else:
    print("Friendship")
