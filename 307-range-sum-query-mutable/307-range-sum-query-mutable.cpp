class NumArray {
    vector<int> tree, arr;
    int n;
    
    int buildBT(int i, int j, int idx, vector<int> &nums, vector<int> &tree) {
        if(i>j) return 0;
        if(i==j) return tree[idx] = nums[i];
        int m = i + (j-i)/2;
        return tree[idx] = buildBT(i, m, idx*2+1, nums, tree) + buildBT(m+1, j, idx*2+2, nums, tree);
    }
    
    int getSum(int i, int j, int &left, int &right, int idx, vector<int> &tree) {
        if(i>j) return 0;
        if(j<left || i>right) return 0;
        if(i>=left && j<=right) return tree[idx];
        int m = i + (j-i)/2;
        return getSum(i, m, left, right, idx*2+1, tree) + getSum(m+1, j, left, right, idx*2+2, tree);
    }
    
    void getUpdate(int i, int j, int idx, int &index, int &diff, vector<int> &tree) {
        if(i > index || j<index) return;
        tree[idx] += diff;
        if(i<j) {
            int m = i +  (j-i)/2;
            getUpdate(i, m, idx*2+1, index, diff, tree);
            getUpdate(m+1, j, idx*2+2, index, diff, tree);
        }
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(n*4);
        arr = nums;
        buildBT(0, n-1, 0, nums, tree);
    }
    
    void update(int index, int val) {
        int diff = -arr[index] + val;
        arr[index] = val;
        getUpdate(0, n-1, 0, index, diff, tree);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, n-1, left, right, 0, tree);
    }
};