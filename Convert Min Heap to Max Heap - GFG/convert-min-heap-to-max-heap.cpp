//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int n){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    void heapify(vector<int> &a,int n,int i){
        while(1){
            int l=2*i+1;
            int r=2*i+2;
            int largest=i;
            if(l<n && a[l]>a[largest]){
                largest=l;
            }
            if(r<n && a[r]>a[largest]){
                largest=r;
            }
            if(largest!=i){
                swap(a[largest],a[i]);
                i=largest;
            }
            else{
                break;
            }
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends