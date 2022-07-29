class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        for(int i=0;i<words.size();i++){
            bool flag=true;
            unordered_map<char,char>m;
            vector<bool>visited(26,false);
            for(int j=0;j<pattern.size();j++){
                
                if(m.count(pattern[j])<=0&&visited[words[i][j]-'a']==false){
                    m[pattern[j]]=words[i][j];
                    visited[words[i][j]-'a']=true;
                }
                else{
                    if((m.count(pattern[j])<=0&&visited[words[i][j]-'a']==true)||m[pattern[j]]!=words[i][j]){
                        flag=false;
                        
                        break;
                    }
                    
                }
            }
            if(flag){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};