class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxPro=0;
        int minPri=INT_MAX;
        for(int i=0;i<n;i++){
            minPri=min(minPri,prices[i]);
            maxPro=max(maxPro,prices[i]-minPri);
        }
        return maxPro;
    }
};