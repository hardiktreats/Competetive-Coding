#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set s;
        vector<int> ans;
        int n = nums.size();
        ans.push_back(0);
        s.insert({nums[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            ans.push_back(s.order_of_key({nums[i], i}));
            s.insert({nums[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};