//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperbound(vector<int> &A,int mid){
        int l=0;
        int h=A.size()-1;
        while(l<=h){
            int md=(l+h)>>1;
            if(A[md]<=mid){
                l=md+1;
            }
            else{
                h=md-1;
            }
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low=0;
        int high=1e9;
        int n=R;
        int m=C;
        while(low<=high){
            int mid=(low+high)>>1;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=upperbound(matrix[i],mid);
            }
            if(cnt<=(n*m)>>1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends