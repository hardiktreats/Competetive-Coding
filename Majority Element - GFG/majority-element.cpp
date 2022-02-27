// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size){
       int temp1=-1;
       int count=0;
       int temp2=a[0];
       sort(a,a+size);
       for(int i=0;i<size;i++){
       if(a[i]==temp2){
       count++;
         if(count>size/2)
           return temp2;
       }
       else{
       temp2=a[i];
       count=1;
       }
   }
   return temp1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends