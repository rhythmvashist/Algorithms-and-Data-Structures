/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int maximum(int left,int right){
        if (left>right){
            return left;
        } 
        else{
            return right;
        }
        
    }

    int  getHeight(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1+maximum(left,right);  
        
    }

    int maxDepth(TreeNode* root) {
        return getHeight(root);
          
    }
};

