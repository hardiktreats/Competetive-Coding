class Solution {
public:
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size= arr.size();
        int count =0;
        vector<int> ans;
        if(x < arr[0]){
            int temp = 0;
            while(count < k){
                ans.push_back(arr[temp]);
                temp++;
                count++;
            }
            
        }
        
        else if(x > arr[size -1]){
            int temp = size-1;
            while(count < k){
                ans.push_back(arr[temp]);
                temp--;
                count++;
            }
            
        }
        else{
            int i =size-1;
            while(arr[i]> x){
                i--;
            }
            
            int j = i+1;
            while(count <k){
                if(i >=0 && j< size && abs(x - arr[i]) <= abs(x-arr[j])){
                    ans.push_back(arr[i]);
                    i--;
                }
                else if(i >=0 && j <size && abs(x - arr[i]) > abs(x-arr[j])){
                    ans.push_back(arr[j]);
                    j++;
                }
                else{
                   break; 
                }
                count++;
            }
            while(count <k){
                if(i == -1){
                    ans.push_back(arr[j]);
                    j++;
                }else{
                    ans.push_back(arr[i]);
                    i--;
                }
                count++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};