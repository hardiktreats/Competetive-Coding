//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void summ(int ind,int sum,vector<int> &arr,vector<int> &ds){
        if(ind==arr.size()){
            ds.push_back(sum);
            return ;
        }
        summ(ind+1,sum+arr[ind],arr,ds);
        summ(ind+1,sum,arr,ds);
    } 
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ds;
        int sum=0;
        summ(0,sum,arr,ds);
        return ds;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends