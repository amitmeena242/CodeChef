#include<stdio.h>


int reverse(int x)
{

int num=0;
while(x>0){
num=num*10+x%10;
x=x/10;
}
return num;
}

int main()
{

int t,n1,n2,count=0;
scanf("%d",&t);

while(t>0)
{
scanf("%d",&n1);
count=0;
n2=reverse(n1);

while(n1!=n2)
{
n1=n1+n2;
n2=reverse(n1);
count++;
}

printf("%d %d\n",count,n1);
t--;
}


return 0;
}
