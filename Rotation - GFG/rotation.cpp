//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int low=0;
	    int high=n-1;
	    int mini=INT_MAX;
	    int finalmini=INT_MAX;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[low]<=arr[high]){
	            if(arr[low]<finalmini){
	                mini=low;
	                finalmini=arr[low];
	            }
	            break;
	        }
	        if(arr[low]<=arr[mid]){
	            if(arr[low]<finalmini){
	                mini=low;
	                finalmini=arr[low];
	            }
	            low=mid+1;
	        }
	        else{
	            
	            high=mid-1;
	            if(arr[mid]<finalmini){
	                mini=mid;
	                finalmini=arr[mid];
	            }
	        }
	    }
	    return mini;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends