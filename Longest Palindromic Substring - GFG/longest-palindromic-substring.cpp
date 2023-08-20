//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<vector<bool>> &dp ,int i,int j,string &s){
        if(i==j){
            return dp[i][j]=true;
        }
        if(j-i==1){
            if(s[i]==s[j]){
                return dp[i][j]=true;
            }
            else{
                return dp[i][j]=false;
            }
        }
        if(s[i]==s[j] && dp[i+1][j-1]==true){
            return dp[i][j]=true;
        }
        else{
            return dp[i][j]=false;
        }
    }
    string longestPalindrome(string s){
        int n=s.size();
        int maxLen=0;
        int startindex = 0;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                solve(dp,i,j,s);
                if(dp[i][j]==true){
                    if(j-i+1>maxLen){
                        startindex=i;
                        maxLen=j-i+1;
                    }
                }
            }
        }
        return s.substr(startindex,maxLen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends