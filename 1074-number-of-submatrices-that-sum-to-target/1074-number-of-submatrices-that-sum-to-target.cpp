class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size(), count = 0;
        
        for (int i = 0; i < m; i++){      
            vector<int> CumulativeColumns = matrix[i]; 
            for (int j = i; j < m; j++){
                unordered_map<int,int> sumCount;         
                int totalSum = 0;
                
                for (int k = 0; k < n; k++){
                    totalSum += CumulativeColumns[k];        
                    if (totalSum == target) count++;        
                    if (sumCount.count(totalSum-target)) count += sumCount[totalSum-target];
                    sumCount[totalSum]++;                          
                    if (j < m - 1) CumulativeColumns[k] += matrix[j+1][k];   
                }
            }
        }
        return count;
    }
};