// Given an n-ary tree, return the preorder traversal of its nodes' values.
#include <iostream>
#include <vector>
#include <stack>
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    
    // vector<int> preorder(Node* root) {
    //     vector<int> res;
    //     prorder(root,res);
    //     return res;
    // }

    // void prorder(Node*root ,vector<int> &rs){
    //     if (root ==nullptr) 
    //         return ;
        
    //     rs.push_back(root->val);
    //     for(auto child: root->children){
    //         if (child!=nullptr){
    //             prorder(child,rs);   
    //         }
                
    //     }
    //     return;
    // }
  
      vector<int> preorder(Node* root) {
        if(root==nullptr) 
            return {};
        stack<Node*> st;
        vector<int> ans;
        st.push(root);
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->val);
            for(int i=(node->children).size()-1;i>=0;--i){
                st.push(node->children[i]);
            }
        }
        return ans;
    }
};

