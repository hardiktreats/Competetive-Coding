//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	    int binary(int arr[], int n, int x) {
      int s = 0;
      int e = n - 1;
    
      while (s <= e) {
        int m = (s + e) / 2;
    
        if (arr[m] == x) {
          return m;
        } else if (arr[m] < x) {
          s = m + 1;
        } else {
          e = m - 1;
        }
      }
      return -1;
    }

    int count(int arr[], int n, int x) {
      // code here
      // get the index of X in array
      int idx = binary(arr, n, x);
    
      // if X does not exist return 0;
      if (idx == -1) {
        return 0;
      }
    
      int k = 1;
      int left = idx - 1;
    
      // check left half for X
      while (left >= 0 && arr[left] == x) {
        k++;
        left--;
      }
      // check right half for X
      int right = idx + 1;
      while (right < n && arr[right] == x) {
        k++;
        right++;
      }
    
      return k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends