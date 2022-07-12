class Solution {
    bool solve(int i,vector<int> &sides,vector<int> &ms)
    {
        if(i==ms.size())
        {
            return (sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0 );
        }
        for(int j=0;j<4;j++)
        {
            if(ms[i]>sides[j])continue;
            sides[j]-=ms[i];
            if( solve(i+1,sides,ms)) return 1;
            sides[j]+=ms[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& ms) {
        int sum=0;
        sort(ms.begin(),ms.end(),greater<int>());
        for(auto i:ms)
            sum+=i;
        int find=sum/4;
        if(sum%4!=0 || ms.size()<4) return false;
        vector<int>sides(4,find);
        return solve(0,sides,ms);
    }
};