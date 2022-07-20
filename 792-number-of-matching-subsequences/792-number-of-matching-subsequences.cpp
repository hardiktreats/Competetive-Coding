class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        //we will be form map to count occurences of particular word to avoid re calculation and this will reduce time
        unordered_map<string,int> mp;
        for(int i= 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto x : mp){
            string str = x.first;
            int n = str.size();
            int i = 0, j = 0;
            while(i < n && j < s.size()){
                if(str[i] == s[j]){
                    i++;
                }
                j++;
            }
            if(i == n){
                count += x.second;  //if we reach the length of string str then this word in our string s. so we increase our count by the number of times it occurred in words instead of incrementing by 1
            }
        }
        
        return count++;
    }
};