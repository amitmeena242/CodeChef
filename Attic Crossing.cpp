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
	      
	      int n= sc.nextInt();
	      
	      for(int i=0;i<n;i++)
	      {
	        String s=sc.next();
	        
	        int x= 0,d=0,m=0;
	        
	        for(int j=0;j<s.length();j++)
	        {
	            x= 0;
	            while(s.charAt(j)=='.')
	            {
	                j++;
	                x++;
	            }
	            
	           if(x>m)
	           {
	               d++;
	               m=x;
	           }
	        }
	       System.out.println(d);
	      }
	  }
	  
	
}
