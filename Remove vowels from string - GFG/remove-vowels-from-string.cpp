//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    public:
    	string removeVowels(string str) {
    	    vector<char> vowels= {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
    	    for(int i=0;i<str.size();i++){
    	        if(find(vowels.begin(),vowels.end(),str[i])!=vowels.end()){
    	            str = str.replace(i,1,"");
    	            i-=1;
    	        }
    	    }
    	    return str;
    	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s, ch; 

	    getline(cin, s);  
   		
       
   		Solution ob;
   		cout << ob.removeVowels(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends