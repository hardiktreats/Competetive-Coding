class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
               long cursor = 0;
        deque<int> dq;
        
        int i = nums.size() - 1;
        for(;i >= 0; i--)
        {
            cursor = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);
            
            while(!dq.empty() and cursor > nums[dq.back()]) 
            {
                dq.pop_back();
            }
            dq.push_back(i);   
            
            if(dq.front() >= i+k) dq.pop_front();
            
            nums[i] = cursor;
        }
        return cursor;
    }
  
};