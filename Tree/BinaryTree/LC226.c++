/*
PROBLEM STATEMENT:  226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

            4                4
          /   \            /   \
         2     3    -->   3     2
        / \   / \        / \    / \
       9   6  2  1      1   2  6   9
*/


# include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
public:

    void invert(TreeNode* root){
        if(root == NULL)
            return;
        
        swap(root->left,root->right);
        invert(root->left);
        invert(root->right);    
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        invert(root);

        return root;
    }
};