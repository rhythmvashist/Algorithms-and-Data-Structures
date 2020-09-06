// All Elements in Two Binary Search Trees
// Given two binary search trees root1 and root2.

// Return a list containing all the integers from both trees sorted in ascending order.

 

// Example 1:


// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:

// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
// Output: [-10,0,0,1,2,5,7,10]
// Example 3:

// Input: root1 = [], root2 = [5,1,7,0,2]
// Output: [0,1,2,5,7]
// Example 4:

// Input: root1 = [0,-10,10], root2 = []
// Output: [-10,0,10]


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode (int x ,TreeNode* left,TreeNode*right):val(x),left(left),right(right){}
};

void bfs(TreeNode* root,vector<int> & list){
    queue<TreeNode*> q;
    TreeNode* temp;
    if(root == nullptr)return;
    q.push(root);

    while(!q.empty()){
        temp=q.front();
        q.pop();
        list.push_back(temp->val);
        if(temp->left!=nullptr) q.push(temp->left);
        if(temp->right!=nullptr) q.push(temp->right);
    }
}


vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> llist;
        vector<int> rlist;
        
        llist=bfs(root1);
        rlist=bfs(root2);
    
        llist.insert(llist.end(),rlist.begin(),rlist.end());
        
        sort(llist.begin(),llist.end());
        return llist;
        
}