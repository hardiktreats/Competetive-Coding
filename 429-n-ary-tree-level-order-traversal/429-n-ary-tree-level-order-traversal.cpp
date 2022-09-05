class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
	    //base case
        if(root == NULL) return {};               
        
        queue<Node*>q;
        q.push(root);
        
        vector<vector<int>>res;
        while(!q.empty()){
            int sz = q.size();
            vector<int>currLevel;
            for(int i=0; i<sz; i++){
                Node* currNode = q.front(); q.pop();
                currLevel.push_back(currNode->val);
                
                for(Node* nextLevel : currNode->children) q.push(nextLevel);
            }
            res.push_back(currLevel);
        }        
        return res;
    }
};