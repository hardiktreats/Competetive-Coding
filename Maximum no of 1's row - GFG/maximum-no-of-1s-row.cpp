// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &mat, int N, int M){
            int j = 0;
   int maxrow = 0;
   j = M - 1;
   for (int i = 0; i < N; i++) 
   {
     bool flag=false; 
   while (j >= 0 && mat[i][j] == 1) 
       {
           j = j - 1;
           flag=true ;
         }
     if(flag==true)
       {
           maxrow = i;
       }
   }
   return maxrow;
       }
        
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends