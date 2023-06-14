//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &arr){
        int ans=0;
        int l=0;
        int r=0;
        map<int,int> mp;
        while(r<n){
            mp[arr[r]]++;
            if(mp.size()<=2){
                ans=max(ans,r-l+1);
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[l]]--;
                    if(mp[arr[l]]==0){
                        mp.erase(arr[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends