// { Driver Code Starts
#include<stdio.h>


 // } Driver Code Ends
//User function Template for C

//Function to rotate an array by d elements in counter-clockwise direction. 
void rotateArr(int arr[], int d, int n){
    int a[n];
    for(int k=0;k<n;k++){
        a[k]=arr[(k+d)%n];
    }
    for(int i=0;i<n;i++){
        arr[i]=a[i];
    }
}

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	scanf("%d",&t);
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    scanf("%d%d",&n, &d);
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        scanf("%d",&arr[i]);
	    }
	    //calling rotateArr() function
	    rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        printf("%d ",arr[i]);
	    }
	    printf("\n");
	}
	return 0;
}  // } Driver Code Ends