// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int smallestSubstring(string s){
   unordered_map<char, int> mp;
       
       int count = 0 ;
       int n = s.length(); 
       int start = 0, end = 0; 
       int ans = INT_MAX; 
       
       while(end < n)
       {
            mp[s[end]]++; 
           if(mp.size() == 3)
           {
               while(mp.size() == 3)
               { 
                 //  cout<<end<<" "<<start<<endl; 
                    ans = min(ans, end - start + 1); 
                   mp[s[start]]--;
                   if(mp[s[start]] == 0)
                   {
                       mp.erase(s[start]);
                   }
                   start++; 
               }
           }
           end++; 
       }
       return ans==INT_MAX?-1:ans; 
   }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends