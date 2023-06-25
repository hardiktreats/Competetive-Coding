//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

Node* lastRightChild(Node* root){
    if(root->right==NULL){
        return root;
    }
    return lastRightChild(root->right);
}
// Function to delete a node from BST.
Node* helper(Node* root){
    if(root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastRight = lastRightChild(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node *deleteNode(Node *root, int X) {
    if(root==NULL){
        return NULL;
    }
    if(root->data==X){
        return helper(root);
    }
    Node* temp=root;
    while(root!=NULL){
        if(root->data>X){
            if(root->left!=NULL && root->left->data==X){
                root->left=helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->data==X){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return temp;
}
