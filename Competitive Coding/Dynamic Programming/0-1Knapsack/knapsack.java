import java.util.*;


class Knapsack
{
 
    // A function to return maximum of two integers
    static int maximum(int a, int b) 
      {
          if(a>b) 
          return a; 
          else 
          return b; 

      }
      
   // Returns the maximum value that can be put in a knapsack of capacity W
    static int  knapSack(int W, int wt[], int val[], int n)
    {
         int  i, w;
     int K[][] = new int[n+1][W+1];
      
     // Build table K[][] in bottom up manner
     for (i = 0; i <= n; i++)
     {
         for (w = 0; w <= W; w++)
         {
             if (i==0 || w==0)
                  K[i][w] = 0;
             else if (wt[i-1] <= w)
                   K[i][w] = maximum(val[i-1] + K[i-1][w-wt[i-1]] ,  K[i1][w]);
             else
                   K[i][w] = K[i-1][w];
         }
      }
      
      Return  K[n][W];
    }
 
   
   
    public static void main(String args[])
    {
		 
        Scanner s=new Scanner(System.in);
        System.out.println(“Enter number of objects”);
        int n=s.nextInt();
        int val[]=new int[n];
        int wt[] = new int[n];
        System.out.println(“Enter values of objects”);


        for(int i=0;i<n;i++)
          {
            val[i]=s.nextInt();
          }

        System.out.println(“Enter weights of object”);
        for(int i=0;i<n;i++)
          {
              wt[i]=s.nextInt();
          }


           System.out.println(“Enter the maximum weight”);
           int  W = s.nextInt();
           System.out.println(knapSack(W, wt, val, n));
            }
}

