class Solution {
public:
     int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        int n=properties.size(),i=n-2,max_def=properties[n-1][1],ans=0;
        while(i>=0 && properties[i][0]==properties[i+1][0]) i--;
        while(i>=0)
        {
            int cur_max_def=properties[i][1];
            if(properties[i][1]<max_def) ans++;
            i--;
            while(i>=0 && properties[i][0]==properties[i+1][0])
            {
                if(properties[i][1]<max_def) ans++;
                cur_max_def=max(properties[i][1],cur_max_def);
                i--;
            }
            max_def=max(max_def,cur_max_def);
        }
        return ans;
    }
};