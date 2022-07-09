// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
     if(a.size()!=b.size())
            return false;
        
        vector<int> v(26,0);
        int i;
        for(i=0;i<a.size();i++)
            v[a[i]-'0'-49]++;
        for(i=0;i<b.size();i++)
            v[b[i]-'0'-49]--;
        for(i=0;i<v.size();i++)
        {
            if(v[i]!=0)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends