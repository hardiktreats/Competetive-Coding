//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string result = "";
        string word = "";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='.'){
                result += word + '.';
                word = "";
            }
            else{
                word = s[i] + word;
            }
        }
        return (result+word);
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends