// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n){
        long long int p=0;
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        for(int i=0;i<n;i++)
            p+=a[i]*b[i];
        return p;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}  // } Driver Code Ends