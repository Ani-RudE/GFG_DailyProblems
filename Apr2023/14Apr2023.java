
//{ Driver Code Starts
import java.io.*;
import java.util.*;

class IntArray {
     public static int[] input(BufferedReader br, int n) throws IOException {
          String[] s = br.readLine().trim().split(" ");
          int[] a = new int[n];
          for (int i = 0; i < n; i++)
               a[i] = Integer.parseInt(s[i]);

          return a;
     }

     public static void print(int[] a) {
          for (int e : a)
               System.out.print(e + " ");
          System.out.println();
     }

     public static void print(ArrayList<Integer> a) {
          for (int e : a)
               System.out.print(e + " ");
          System.out.println();
     }
}

class GFG {
     public static void main(String[] args) throws IOException {
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
          int t;
          t = Integer.parseInt(br.readLine());
          while (t-- > 0) {

               int N;
               N = Integer.parseInt(br.readLine());

               int[] color = IntArray.input(br, N);

               int[] radius = IntArray.input(br, N);

               Solution obj = new Solution();
               int res = obj.finLength(N, color, radius);

               System.out.println(res);

          }
     }
}

// } Driver Code Ends

class Solution {
     public static int finLength(int N, int[] color, int[] radius){

          Stack<Integer> s1 = new Stack<>();
          Stack<Integer> s2 = new Stack<>();

          for (int i = 0; i < N; i++)
          {
               if (s1.isEmpty() || s2.isEmpty())
               {
                    s2.push(radius[i]);
                    s1.push(color[i]);
                    continue;

               }
               else if (!s1.isEmpty() && color[i] == s1.peek())
               {
                    if (!s2.isEmpty() && radius[i] == s2.peek())
                    {
                         s1.pop();
                         s2.pop();
                    }
                    else
                    {
                         s1.push(color[i]);
                         s2.push(radius[i]);
                    }
               }
               else
               {
                    s1.push(color[i]);
                    s2.push(radius[i]);
               }
          }

          return s1.size();
     }
}