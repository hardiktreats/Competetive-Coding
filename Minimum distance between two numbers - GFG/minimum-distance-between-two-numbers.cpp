// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
       int x_index=-1;
       int y_index=-1;
       int result=INT_MAX;
       for(int i=0; i<n; i++){
           if(a[i]==x){
              x_index=i;
           }
           if(a[i]==y){
               y_index=i;
           }
           if(x_index!=-1&&y_index!=-1){
               result=min(result,abs(x_index-y_index));
           }
       }
       if(result==INT_MAX){
               return -1;
           }
       return result;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends