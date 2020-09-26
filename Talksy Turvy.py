import sys
#sys.stdin = open('ip.txt', 'r') 
#sys.stdout = open('op.txt', 'w')
try:
    
    def main():
        t=1
        # t=int(sys.stdin.readline())
        while(t):
            s=sys.stdin.readline()
            l=s.split()
            for i in range(len(l)):
                if(l[i][0]=='a' or l[i][0]=='e' or l[i][0]=='o' or l[i][0]=='i' or l[i][0]=='u'):
                    sys.stdout.write(l[i]+'d')
                else:
                    sys.stdout.write(l[i][1:]+l[i][0]+'d')
                for j in range(i+1):
                    sys.stdout.write('u')
                sys.stdout.write(" ")

            t-=1
        
    main()
     
except Exception as e:
    sys.stdout.write("ErrOR : "+str(e))
