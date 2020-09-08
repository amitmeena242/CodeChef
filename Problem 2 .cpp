/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;


/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t=sc.nextInt();
		
		for(int i=0;i<t ;i++)
		{
		    int k=sc.nextInt();
	
		for(int j=k+1;j<=99999; j++)
		{
		 if(isPalindrome(j))
		 {
	        String s1=eliminateZeroes(j);
	        int num=Integer.parseInt(s1);
	        System.out.println(num);
	        break;
	      }
	    	
	    }
	  }
    }
	
    static boolean isPalindrome(int n)
	{
	    int temp=n;
	    int rev=0;
	    
	    while(n!=0) 
	    {
        rev=rev*10 +n%10;
        n/= 10;
        }
    
    if(rev==temp)
    return true;
    else
    return false;
	}
	
	
    static String eliminateZeroes(int n)
	{
	    String s =Integer.toString(n);
	    int k=0;
	     while (k< s.length() && s.charAt(k) == '0') 
         k++; 
  
        StringBuffer sb = new StringBuffer(s); 
        sb.replace(0, k, ""); 
        return sb.toString(); 
	}	
}
