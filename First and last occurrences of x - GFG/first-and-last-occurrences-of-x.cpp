//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int first=0;
    int last=n-1;
    while(1){
        if(arr[first]!=x){
            first++;
        }
        else{
            break;
        }    
    }  
    while(1){
         if(arr[last]!=x){
             last--;
         }
        else{
            break;
        }    
    } 
    if(last<first){
        return {-1,-1};
    }
    return {first,last};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends