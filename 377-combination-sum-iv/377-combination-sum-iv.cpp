class Solution {
public:
    int combinationSum4( vector<int>& nums,int target) {
        unsigned int dp[target+1]; 
        fill(dp,dp+target+1,0);
        int n=nums.size();

        dp[0]=1;  //dp[0] is 1 because there is 1 way to get sum 0 by not selecting anything
        
        for(int amt=0;amt<=target ;amt++)
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=amt)
                    dp[amt]= dp[amt]+dp[amt-nums[j]];
            }
        return dp[target];
    }
};