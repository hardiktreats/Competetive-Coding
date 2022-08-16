class Solution {
public:
    int firstUniqChar(string s) {
       int size = s.size(); 
       int array[26];
        for(int i=0;i<26;i++)array[i]=0;
        for(int i = 0;i<size;i++){
            array[s[i]-'a']++;
        }
        for(int it = 0;it<size;it++){
            if(array[s[it]-'a']==1)return it;
        }
        return -1;
    }
};