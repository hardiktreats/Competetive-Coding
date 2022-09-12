class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
                continue;
            }
            else{
                if(score==0 || i==j)
                    return score;
                score--;
                power+=tokens[j];
                j--;
                continue;
            }
            
        }
        return score;
    }
};