//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    bool isLeaf(Node* root){
        if(!root->left and !root->right) return true;
        else return false;
    }
    void addLeftBoundary(Node* root, vector<int> & v){
        Node* temp=root->left;
        while(temp){
            if(!isLeaf(temp)){
                v.push_back(temp->data);
            }
            if(temp->left){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
    }
    void addRightBoundary(Node* root,vector<int> &v){
        Node* temp=root->right;
        vector<int> tmp;
        while(temp){
            if(!isLeaf(temp)){
                tmp.push_back(temp->data);
            }
            if(temp->right){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        reverse(tmp.begin(),tmp.end());
        for(auto it:tmp){
            v.push_back(it);
        }
    }
    void addLeaves(Node* root,vector<int> &v){
        if(isLeaf(root)){
            v.push_back(root->data);
            return ;
        }
        if(root->left){
            addLeaves(root->left,v);
        }
        if(root->right){
            addLeaves(root->right,v);
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        if(!isLeaf(root)){
            v.push_back(root->data);
        }
        addLeftBoundary(root,v);
        addLeaves(root,v);
        addRightBoundary(root,v);
        return v;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends