// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n){
    int ans=1,index=0;
    sort(arr,arr+n);
    if(arr[0]==0){
        index=1;
    }
    for(int i=index;i<n;i++){ 
       if(arr[i]>0){
           if(arr[i]==ans-1){
               continue;
           }
           if(arr[i]!=ans){
               return ans;
           }
       else{
           ans++;
        }
      }
    }
    return ans;   
   } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends