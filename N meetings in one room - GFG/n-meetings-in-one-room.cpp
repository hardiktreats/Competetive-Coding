//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int start;
        int finish;
        int index;
    };
    static bool comparator(struct meeting m1,struct meeting m2){
        if(m1.finish<m2.finish) return true;
        else if(m1.finish>m2.finish) return false;
        else if(m1.index<m2.index)return true;
        else return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start=s[i],meet[i].finish=end[i],meet[i].index=i+1;
        }
        sort(meet,meet+n,comparator);
        vector<int> ans;
        int limit=meet[0].finish;
        ans.push_back(meet[0].index);
        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                limit=meet[i].finish;
                ans.push_back(meet[i].index);
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends