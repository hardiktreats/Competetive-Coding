//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    void substr(string str1,string str2,vector<vector<int>> &dp){
	        int n = str1.size();
	        if(n==0){
	            return ;
	        }
	        for(int i=0;i<n+1;i++){
	            for(int j=0;j<n+1;j++){
	                if(i==0 || j==0){
	                    dp[i][j]=0;
	                }
	            }
	        }
	        for(int i=1;i<=n;i++){
	            for(int j=1;j<=n;j++){
	                if(str1[i-1] == str2[j-1] && i!=j){
	                    dp[i][j] = 1+dp[i-1][j-1];
	                }
	                else{
	                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	    }
	    int LongestRepeatingSubsequence(string str){
	        int n = str.size();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    substr(str,str,dp);
		    return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends